type 'v nnf =
| NNFLit of bool * 'v
| NNFConj of 'v nnf * 'v nnf
| NNFDisj of 'v nnf * 'v nnf

type 'v formula =
| Var of 'v
| Neg of 'v formula
| Conj of 'v formula * 'v formula
| Disj of 'v formula * 'v formula

let rec to_nnf = function
| Var v -> NNFLit (true, v)
| Conj (p1, p2) -> NNFConj (to_nnf p1, to_nnf p2)
| Disj (p1, p2) -> NNFDisj (to_nnf p1, to_nnf p2)
| Neg p -> match p with
  | Var v -> NNFLit (false, v)
  | Conj (p1, p2) -> NNFDisj (to_nnf (Neg p1), to_nnf (Neg p2))
  | Disj (p1, p2) -> NNFConj (to_nnf (Neg p1), to_nnf (Neg p2))
  | Neg p -> to_nnf p
