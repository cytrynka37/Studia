open Ast

let parse (s : string) : expr =
  Parser.prog Lexer.read (Lexing.from_string s)

type value =
  | VInt of int
  | VBool of bool

let eval_op (op : bop) (v1 : value) (v2 : value) : value =
  match op, v1, v2 with
  | Add,  VInt i1, VInt i2 -> VInt ((i1 + i2) mod 5)
  | Sub,  VInt i1, VInt i2 -> VInt ((i1 - i2) mod 5)
  | Mult, VInt i1, VInt i2 -> VInt ((i1 * i2) mod 5)
  | Div,  VInt i1, VInt i2 -> VInt ((i1 / i2) mod 5)
  | Eq,   VInt i1, VInt i2 -> VBool (i1 = i2)
  | NEq,  VInt i1, VInt i2 -> VBool (i1 <> i2)
  | Ls,  VInt i1, VInt i2 -> VBool (i1 < i2)
  | LEq,  VInt i1, VInt i2 -> VBool (i1 <= i2)
  | Gr,  VInt i1, VInt i2 -> VBool (i1 > i2)
  | GEq,  VInt i1, VInt i2 -> VBool (i1 >= i2)
  | _ -> failwith "type error"

let rec eval (e : expr) : value =
  match e with
  | Int n -> VInt (n mod 5)
  | Bool b -> VBool b
  | If (p, t, e) ->
      (match eval p with
      | VBool true -> eval t
      | VBool false -> eval e
      | _ -> failwith "type error") 
  | Binop (op, e1, e2) -> eval_op op (eval e1) (eval e2)
  | Logop (op, e1, e2) -> match (op, eval e1) with
    | And, VBool false -> VBool false
    | And, VBool true -> eval e2 
    | Or, VBool false -> eval e2 
    | Or, VBool true -> VBool true
    | _ -> failwith "type error"
  
let interp (s : string) : value =
  eval (parse s)
