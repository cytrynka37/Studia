(*
Zasada Indukcji dla Typu NNF:
dla każdej własności P,
jeśli P(NNFLit (b, v)), gdzie b jest flagą boolowską określającą, czy formuła jest zanegowana, v jest zmienną zdaniową,
oraz jeśli właściwość P zachodzi dla formuł p1 i p2, to również zachodzi dla NNFConj (p1, p2) oraz NNFDisj (p1, p2) (gdzie p1 i p2 są w nnf),
to dla każdej formuły zachodzi P(p1)
*)

type 'v nnf =
| NNFLit of bool * 'v
| NNFConj of 'v nnf * 'v nnf
| NNFDisj of 'v nnf * 'v nnf

let formula1 = NNFConj (NNFLit (true, "p"), NNFLit (false, "q"))
let formula2 = NNFDisj (NNFLit (true, "r"), NNFLit (true, "s"))

let rec negate_nnf = function
  | NNFLit (b, v) -> NNFLit (not b, v)
  | NNFConj (p1, p2) -> NNFDisj (negate_nnf p1, negate_nnf p2)
  | NNFDisj (p1, p2) -> NNFConj (negate_nnf p1, negate_nnf p2)


let rec string_of_nnf = function
  | NNFLit (true, v) -> v
  | NNFLit (false, v) -> "¬" ^ v
  | NNFConj (p1, p2) -> "(" ^ string_of_nnf p1 ^ " ∧ " ^ string_of_nnf p2 ^ ")"
  | NNFDisj (p1, p2) -> "(" ^ string_of_nnf p1 ^ " ∨ " ^ string_of_nnf p2 ^ ")"


(*neg_nnf (neg_nnf φ) ≡ φ dla dowolnej formuły φ
1. Krok bazowy: Załóżmy, że φ jest  literałem NNFLit(b, v), gdzie b jest typu bool, v jest zmienną zdaniową.
Pokażmy, że neg_nnf neg_nnf NNFLit(b, v)) = NNFLit(b, v). 
a) b = true: neg_nnf (neg_nnf NNFLit(true, v))) = neg_nnf (NNFlit (false, v)) = NNFlit (true, v)
b) b = false: neg_nnf (neg_nnf NNFLit(false, v))) = neg_nnf (NNFlit (true, v)) = NNFlit (false, v)

2. Weźmy dwie dowolne formuły p1, p2 i załóżmy że spełnione jest dla nich neg_nnf (neg_nnf φ) ≡ φ.
a) NNFConj (p1, p2): neg_nnf (neg_nnf NNFConj (p1, p2)) = neg_nnf (NNFDisj (negate_nnf p1, negate_nnf p2)) = 
= NNFConj (negate_nnf (negate_nnf p1), negate_nnf (negate_nnf p2)) = NNFConj (p1, p2)
b) NNFDisj (p1, p2) - analogiczny
*)