(* ---------- Zad 3 ---------- *)

module Zad3 = struct

open List

type 'a symbol =
  | T of string
  | N of 'a

type 'a grammar = ('a * ('a symbol list) list) list

let generate (g : 'a grammar) (s : 'a) : string = 
  let rec __generate (s : 'a symbol) =
    match s with
    | T terminal -> terminal
    | N non_terminal -> let p = List.assoc non_terminal g in
      let chosen = List.nth p (Random.int (List.length p)) in
        String.concat "" (List.map __generate chosen)
  in
  __generate (N s)

let pol : string grammar =
  [ "zdanie", [[N "grupa-podmiotu"; N "grupa-orzeczenia"]]
  ; "grupa-podmiotu", [[N "przydawka"; N "podmiot"]]
  ; "grupa-orzeczenia", [[N "orzeczenie"; N "dopelnienie"]]
  ; "przydawka", [[T "Piękny "];
                  [T "Bogaty "];
                  [T "Wesoły "]]
  ; "podmiot", [[T "policjant "];
                [T "student "];
                [T "piekarz "]]
  ; "orzeczenie", [[T "zjadł "];
                   [T "pokochał "];
                   [T "zobaczył "]]
  ; "dopelnienie", [[T "zupę."];
                    [T "studentkę."];
                    [T "sam siebie."];
                    [T "instytut informatyki."]]]

(* generate pol "zdanie" *)

let expr : unit grammar =
  [(), [[N (); T "+"; N ()];
        [N (); T "*"; N ()];
        [T "("; N (); T ")"];
        [T "1"];
        [T "2"]]]

(* generate expr () *)

end

(* ---------- Zad 4 ---------- *)

(* List.of_seq (String.to_seq str) *)

module Zad4 = struct

let parens_ok (i : string) : bool = 
  let rec __parens_ok i count =
    match i with
    | [] -> if count = 0 then true else false
    | '(' :: rest -> __parens_ok rest (count + 1)
    | ')' :: rest -> if count > 0 then __parens_ok rest (count - 1) else false
    | _ -> false
  in
  __parens_ok (List.of_seq (String.to_seq i)) 0
end


(* ---------- Zad ---------- 5 *)

module Zad5 = struct

  let parens_ok (i : string) : bool = 
    let rec match_bracket p =
      match p with
      | '(' -> ')'
      | '[' -> ']'
      | '{' -> '}'
      | _ -> failwith "invalid bracket"
    in
    let rec __parens_ok i stack =
      match i with
      | [] -> if List.length stack = 0 then true else false
      | b :: rest -> match b with
        | '[' | '(' | '{' -> __parens_ok rest (b :: stack)
        | ']' | '}' | ')' -> (match stack with
          | [] -> false
          | head :: tail -> if b = match_bracket head then __parens_ok rest tail else false)
        | _ -> false
    in
    __parens_ok (List.of_seq (String.to_seq i)) []

end


(* -- zad 2 --
N = {S}
T = {a, b}
P = {
  S -> e
  S -> a
  S -> aSa
  S -> b
  S -> bSb
}
*)

(* -- zad modulo --
let eval_op (op : bop) (v1 : value) (v2 : value) : value =
  let mod5 n = (n + 5) mod 5 in
  match op, v1, v2 with
  | Add,  VInt i1, VInt i2 -> VInt (mod5 (i1 + i2))
  | Sub,  VInt i1, VInt i2 -> VInt (mod5 (i1 - i2))
  | Mult, VInt i1, VInt i2 -> VInt (mod5 (i1 * i2))
  | Div,  VInt i1, VInt i2 -> VInt (mod5 (i1 / i2))
  | Eq,   VInt i1, VInt i2 -> VBool (i1 = i2)
  | NEq,  VInt i1, VInt i2 -> VBool (i1 <> i2)
  | Less,  VInt i1, VInt i2 -> VBool (i1 < i2)
  | LsEq,  VInt i1, VInt i2 -> VBool (i1 <= i2)
  | Greater,  VInt i1, VInt i2 -> VBool (i1 > i2)
  | GrEq,  VInt i1, VInt i2 -> VBool (i1 >= i2)
  | _ -> failwith "type error"

let rec eval (e : expr) : value =
  match e with
  | Int n -> VInt ((n + 5) mod 5)
  | Bool b -> VBool b
  | If (p, t, e) ->
      (match eval p with
      | VBool true -> eval t
      | VBool false -> eval e
      | _ -> failwith "type error") 
  | Binop (op, e1, e2) -> eval_op op (eval e1) (eval e2)
  *)