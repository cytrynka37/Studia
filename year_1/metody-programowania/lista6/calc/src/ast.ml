(* abstract syntax tree *)

type bop = Mult | Div | Add | Sub | Eq | NEq | Ls | LEq | Gr | GEq

type logop = And | Or

type expr =
  | Int of int
  | Bool of bool
  | Binop of bop * expr * expr
  | Logop of logop * expr * expr 
  | If of expr * expr * expr