open Ast

let parse (s : string) : expr =
  Parser.prog Lexer.read (Lexing.from_string s)

type value =
  | VInt of int
  | VBool of bool

let eval_op (op : bop) (v1 : value) (v2 : value) : value =
  match op, v1, v2 with
  | Add,  VInt i1, VInt i2 -> VInt (i1 + i2)
  | Sub,  VInt i1, VInt i2 -> VInt (i1 - i2)
  | Mult, VInt i1, VInt i2 -> VInt (i1 * i2)
  | Div,  VInt i1, VInt i2 -> VInt (i1 / i2)
  | Eq,   VInt i1, VInt i2 -> VBool (i1 = i2)
  | Lt,   VInt i1, VInt i2 -> VBool (i1 < i2)
  | Gt,   VInt i1, VInt i2 -> VBool (i1 > i2)
  | Leq,  VInt i1, VInt i2 -> VBool (i1 <= i2)
  | Geq,  VInt i1, VInt i2 -> VBool (i1 >= i2)
  | Neq,  VInt i1, VInt i2 -> VBool (i1 <> i2)
  | _ -> failwith "type error"


(* Evaluation via substitution *)

module Subst = struct

let rec subst (x : ident) (s : expr) (e : expr) : expr =
  match e with
  | Binop (op, e1, e2) -> Binop (op, subst x s e1, subst x s e2)
  | If (p, t, e) -> If (subst x s p, subst x s t, subst x s e)
  | Var y -> if x = y
               then s
               else e
  | Let (y, e1, e2) -> if x = y
                         then Let (y, subst x s e1, e2)
                         else Let (y, subst x s e1, subst x s e2)
  | _ -> e
  
let expr_of_value (v : value) : expr =
  match v with
  | VInt a -> Int a
  | VBool a -> Bool a

let rec eval (e : expr) : value =
  match e with
  | Int n -> VInt n
  | Bool b -> VBool b
  | If (p, t, e) ->
      (match eval p with
      | VBool true -> eval t
      | VBool false -> eval e
      | _ -> failwith "type error")
  | Binop (And, e1, e2) ->
      (match eval e1 with
      | VBool true -> eval e2
      | VBool false -> VBool false
      | _ -> failwith "type error")
  | Binop (Or, e1, e2) ->
      (match eval e1 with
      | VBool false -> eval e2
      | VBool true -> VBool true
      | _ -> failwith "type error")
  | Binop (op, e1, e2) -> eval_op op (eval e1) (eval e2)
  | Let (x, e1, e2) -> let s = expr_of_value (eval e1) in
                       eval (subst x s e2)
  | Var x -> failwith ("unbound value " ^ x)

let interp (s : string) : value =
  eval (parse s)

end


(* Evaluation via environments *)

module Env = struct

module M = Map.Make(String)

type env = value M.t

let rec eval_env (env : env) (e : expr) : value =
  match e with
  | Int n -> VInt n
  | Bool b -> VBool b
  | If (p, t, e) ->
      (match eval_env env p with
      | VBool true -> eval_env env t
      | VBool false -> eval_env env e
      | _ -> failwith "type error")
  | Binop (And, e1, e2) ->
      (match eval_env env e1 with
      | VBool true -> eval_env env e2
      | VBool false -> VBool false
      | _ -> failwith "type error")
  | Binop (Or, e1, e2) ->
      (match eval_env env e1 with
      | VBool false -> eval_env env e2
      | VBool true -> VBool true
      | _ -> failwith "type error")
  | Binop (op, e1, e2) -> eval_op op (eval_env env e1) (eval_env env e2)
  | Let (x, e1, e2) ->
      let r = eval_env env e1 in
      let new_env = M.update x (fun _ -> Some r) env in
      eval_env new_env e2
  | Var x ->
      (match M.find_opt x env with
      | Some v -> v
      | None -> failwith ("unbound value" ^ x))

let eval : expr -> value = eval_env M.empty 

let interp (s : string) : value =
  eval (parse s)

let expr_of_value value = 
  match value with
  | VInt n -> Int n
  | VBool b -> Bool b

let cp (e : expr) : expr = 
  let rec eval_env' e env =
    match e with
    | Int _ | Bool _ -> e
    | Var x ->
      (match M.find_opt x env with
      | Some v -> v
      | None -> Var x)
    | Binop(op, e1, e2) -> 
      (match (eval_env' e1 env, eval_env' e2 env) with
      | (Int a, Int b) -> expr_of_value (eval_op op (VInt a) (VInt b))
      | (a, b) -> Binop(op, a, b))
    | If (p, t, e) ->
        (match eval_env' p env with
        | Bool true -> eval_env' t env
        | Bool false -> eval_env' e env
        | other -> If (other, eval_env' t env, eval_env' e env))
    | Let (x, e1, e2) ->
        let r = eval_env' e1 env in
        (match r with
        | Int _  | Bool _ -> eval_env' e2 (M.add x r env)
        | _ -> Let (x, r, eval_env' e2 (M.add x (Var x) env)))
  in
  eval_env' e M.empty

let alpha_equiv (e1 : expr) (e2 : expr) : bool =
  let rec helper (env1 : string M.t) (env2 : string M.t) (e1 : expr) (e2 : expr) : bool =
    match e1, e2 with
    | Int a, Int b -> a = b
    | Bool a, Bool b -> a = b
    | If (p1, t1, e1), If (p2, t2, e2) ->
        helper env1 env2 p1 p2 && helper env1 env2 t1 t2 && helper env1 env2 e1 e2
    | Binop (op1, e1l, e1r), Binop (op2, e2l, e2r) when op1 = op2 ->
        helper env1 env2 e1l e2l && helper env1 env2 e1r e2r
    | Let (x1, e1l, e1r), Let (x2, e2l, e2r) ->
        let new_env1 = M.add x1 x2 env1 in
        let new_env2 = M.add x2 x1 env2 in
        helper env1 env2 e1l e2l && helper new_env1 new_env2 e1r e2r
    | Var x1, Var x2 ->
        (match (M.find_opt x1 env1, M.find_opt x2 env2) with
        | (Some a, Some b) -> a = x2 && b = x1
        | (None, None) -> x1 = x2
        | _ -> false)
    | _ -> false
  in
  helper M.empty M.empty e1 e2

let rename_expr (e : expr) : expr =
  let rec helper path env e =
    match e with
    | Int _ | Bool _ -> e
    | Binop (op, e1, e2) -> Binop (op, helper (path ^ "L") env e1, helper (path ^ "R") env e2)
    | If (p, t, e) -> If (helper (path ^ "P") env p, helper (path ^ "T") env t, helper (path ^ "E") env e)
    | Var x ->
      (match M.find_opt x env with
        | Some name -> name
        | None -> Var x)
    | Let (x, e1, e2) -> 
      let e1' = helper (path ^ "L") env e1 in
      let new_env = M.add x (Var path) env in
      let e2' = helper (path ^ "R") new_env e2 in
      Let (path, e1', e2')
  in
  helper "#" M.empty e

end

