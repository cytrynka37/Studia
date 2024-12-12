type expr =
  | Int of int
  | Add of expr * expr
  | Mult of expr * expr

let rec eval (e : expr) : int =
  match e with
  | Int n -> n
  | Add (e1, e2) -> eval e1 + eval e2
  | Mult (e1, e2) -> eval e1 * eval e2

type rpn_cmd =
  | Push of int
  | RAdd
  | RMult

type rpn = rpn_cmd list

let rec to_rpn (e : expr) : rpn =
  match e with
  | Int n -> [Push n]
  | Add (e1, e2) -> to_rpn e1 @ to_rpn e2 @ [RAdd]
  | Mult (e1, e2) -> to_rpn e1 @ to_rpn e2 @ [RMult]

let rec eval_rpn (r : rpn) (s : int list) : int =
  match r, s with
  | [], [n] -> n
  | Push n :: r', _ -> eval_rpn r' (n :: s)
  | RAdd :: r', n1 :: n2 :: s' -> eval_rpn r' (n2 + n1 :: s')
  | RMult :: r', n1 :: n2 :: s' -> eval_rpn r' (n2 * n1 :: s')
  | _,_ -> failwith "error!"


let x = 2;;

(* ZAD 1 *)

(*

forall e. eval_rpn (to_rpn e) [] = eval e

eval_rpn (to_rpn e) [] = eval_rpn [] [eval e] = eval e



eval_rpn ((to_rpn e) @ rest) s = eval_rpn rest [eval e] :: s

eval_rpn rest [eval Add (e1, e2)] :: s = eval_rpn rest [eval e1 + eval e2] :: s =
eval_rpn [RAdd @ rest] eval e2 :: eval e1 :: s = eval_rpn [(to_rpn e2) @ RAdd @ rest] (eval e1 :: s) = 
eval_rpn [(to_rpn e1) @ (to_rpn e2) @ RAdd @ rest] s
*)

(* ZAD 2 *)

let rec from_rpn (r : rpn) (s : expr list) : expr =
  match r, s with
  | [], [n] -> n
  | Push n :: r', _ -> from_rpn r' (Int n :: s)
  | RAdd :: r', n1 :: n2 :: s' -> from_rpn r' (Add (n2, n1) :: s')
  | RMult :: r', n1 :: n2 :: s' -> from_rpn r' (Mult (n2, n1) :: s')
  | _, _ -> failwith "error"
  
(* ZAD 3 *)

(* porównaj zad 3. z listy 6. *)
let rec random_expr (max_depth : int) : expr =
  if max_depth <= 0 then Int (Random.int 100)
  else
    match Random.int 3 with
    | 0 -> Add (random_expr (max_depth - 1), random_expr (max_depth - 1))
    | 1 -> Mult (random_expr (max_depth - 1), random_expr (max_depth - 1))
    | _ -> Int (Random.int 100)



let rec test (max_depth : int) (sample : int) : bool =
  if sample <= 0 then true
  else
    let random = random_expr max_depth in
    if from_rpn (to_rpn random) [] = random then test max_depth (sample - 1) else false

(* ZAD 4 *)

let rec test_ce (max_depth : int) (sample : int) : expr option =
  if sample <= 0 then None
  else
    let random = random_expr max_depth in
    if from_rpn (to_rpn random) [] = random then test_ce max_depth (sample - 1) else Some random    

(* ZAD 5 *)

type bop = Mult | Div | Add | Sub | Eq | Lt | Gt | Leq | Geq | Neq

module T = struct

type cmd =
  | PushInt of int
  | PushBool of bool
  | Prim of bop
  | Jmp of string
  | JmpFalse of string
  | Grab
  | Access of int
  | EndLet
  | PushClo of string
  | Call of string
  | Return
  | Lbl of string

end
