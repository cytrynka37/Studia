type 'v formula =
| Var of 'v
| Neg of 'v formula
| Conj of 'v formula * 'v formula
| Disj of 'v formula * 'v formula
type 'v nnf =
| NNFLit of bool * 'v
| NNFConj of 'v nnf * 'v nnf
| NNFDisj of 'v nnf * 'v nnf

let rec neg_nnf = function
  | NNFLit (b, v) -> NNFLit (not b, v)
  | NNFConj (p1, p2) -> NNFDisj (negate_nnf p1, negate_nnf p2)
  | NNFDisj (p1, p2) -> NNFConj (negate_nnf p1, negate_nnf p2)
  
let rec eval_nnf sigma = function
| NNFLit (b, v) -> if b then (sigma v) else not (sigma v)
| NNFConj (p1, p2) -> eval_nnf sigma p1 && eval_nnf sigma p2
| NNFDisj (p1, p2) -> eval_nnf sigma p1 || eval_nnf sigma p2

let rec to_nnf f =
  match f with
  | Var v -> NNFLit(true, v)
  | Neg p -> neg_nnf (to_nnf p)
  | Conj (p, q) -> NNFConj(to_nnf p, to_nnf q)
  | Disj (p, q) -> NNFDisj(to_nnf p, to_nnf q)


let rec eval_formula sigma = function
| Var v -> sigma v
| Conj (p1, p2) -> eval_formula sigma p1 && eval_formula sigma p2
| Disj (p1, p2) -> eval_formula sigma p1 || eval_formula sigma p2
| Neg p -> not (eval_formula sigma p)

let a = 4

(*
eval_nnf σ (to_nnf φ) ≡ eval_formula σ φ  
1. Krok bazowy
  Pokażmy, że dla dowolnego wartosciowania o, eval_nnf σ (to_nnf (Var v)) ≡ eval_formula σ (Var v)
  eval_nnf o (to_nnf (Var v)) 
  == (def. to_nnf)
  eval_nnf o (NNFLit (true, v)) 
  == (def. eval_nnf)
  o v 
  == (def. eval_formula)
  eval_formula o (Var v)

2. Krok indukcyjny
  Zalozmy, ze zachodzi P(p1) i P(p2), pokazemy, ze w takim razie zachodzi P(Neg p1), P(Conj(p1, p2)), P(Disj(p1, p2))
  a) eval_nnf o (to_nnf Neg p) ≡ eval_formula o Neg p
     eval_nnf o (to_nnf Neg p)
     == (def. to_nnf)
     eval_nnf o (neg_nnf (to_nnf p))
     == (z zad. 5)
     not (eval_nnf o (to_nnf p))
     == (założenie)
     not (eval_formula o p)
     == (def. eval_formula)
     eval_formula o Neg p
     
  b) eval_nnf σ (to_nnf Conj(p1, p2)) ≡ eval_formula σ Conj(p1, p2)
     eval_nnf σ (to_nnf Conj(p1, p2))
     == (def. to_nnf)
     eval_nnf o (NNFConj (to_nnf p1, to_nnf p2))
     == (def. eval_nnf)
     eval_nnf o (to_nnf p1) && eval_nnf o (to_nnf p2)
     == (założenie)
     eval_formula o p1 && eval_formula o p2
     == (def. eval_formula)
     eval_formula o Conj(p1, p2)

    
  *)
