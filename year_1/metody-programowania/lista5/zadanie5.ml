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

  let rec eval_nnf sigma = function
  | NNFLit (b, v) -> if b then not (sigma v) else sigma v
  | NNFConj (p1, p2) -> eval_nnf sigma p1 && eval_nnf sigma p2
  | NNFDisj (p1, p2) -> eval_nnf sigma p1 || eval_nnf sigma p2

  (* eval_nnf σ (neg_nnf φ) ≡ not (eval_nnf σ φ)
  1. Krok bazowy: eval_nnf o (neg_nnf NNFLit (b, v)) = not (eval_nnf o NNFLit (b, v))
   b = true: eval_nnf o (neg_nnf NNFlit (true, v)) = eval_nnf o NNFLit (false, v) = o v = not (not o v) = not (eval_nnf o NNFlit (true, v))
   b = false: eval_nnf o (neg_nnf NNFLit (false, v)) = eval_nnf o NNLit (true, v) = not (o v) = not (eval_nnf o NNFLit (false, v)) 

  2. Krok indukcyjny: weżmy dowolne formuły p1, p2, i założmy że dla jest dla nich spełnione eval_nnf σ (neg_nnf φ) ≡ not (eval_nnf σ φ).
  NNFConj (p1, p2): eval_nnf o (neg_nnf NNFConj (p1, p2)) = 
  eval_nnf o (NNFDisj (negate_nnf p1, negate_nnf p2)) = 
  eval_nnf o negate_nnf p1 || eval_nnf o negate_nnf p2 =  
  not (eval_nnf o p1) || not (eval_nnf o p2) = 
  not (eval_nnf o p1 && eval_nnf o p2) = 
  not (eval_nnf o NNFConj (p1, p2))
  *)