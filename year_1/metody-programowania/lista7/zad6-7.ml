type ident = string

type qbf =
  | Top
  | Bot
  | Var of ident
  | Forall of ident * qbf
  | Exists of ident * qbf
  | Not of qbf
  | Conj of qbf * qbf
  | Disj of qbf * qbf

(* Zad 6. *)

let rec subst (x : ident) (s : qbf) (f : qbf) : qbf =
  match f with
  | Top -> Top
  | Bot -> Bot
  | Var y -> if x = y then s else f
  | Not p -> Not (subst x s p)
  | Disj (e1, e2) -> Disj (subst x s e1, subst x s e2)
  | Conj (e1, e2) -> Conj (subst x s e1, subst x s e2)
  | Forall (y, e) -> if x = y then Forall (y, e) else Forall (y, subst x s e)
  | Exists (y, e) -> if x = y then Exists (y, e) else Exists (y, subst x s e)

let rec eval (f : qbf) : bool =
  match f with
  | Top -> true
  | Bot -> false
  | Var x -> failwith ("unbound value " ^ x)
  | Not p -> not (eval p)
  | Disj (e1, e2) -> eval e1 || eval e2
  | Conj (e1, e2) -> eval e1 && eval e2
  | Forall (y, e) -> eval (subst y Top e) && eval (subst y Bot e)
  | Exists (y, e) -> eval (subst y Top e) || eval (subst y Bot e)

(* Zad 7. *)
  
module M = Map.Make(String)

type env = bool M.t

let rec eval_env (env : env) (f : qbf) : bool =
  match f with
  | Top -> true
  | Bot -> false
  | Var x -> 
    (match M.find_opt x env with
    | Some y -> y 
    | None -> failwith("unbound value" ^ x))
  | Not p -> not (eval_env env p)
  | Disj (e1, e2) -> (eval_env env e1) || (eval_env env e2)
  | Conj (e1, e2) -> (eval_env env e1) && (eval_env env e2)
  | Forall (y, e) -> eval_env (M.add y true env) e && eval_env (M.add y false env) e
  | Exists (y, e) -> eval_env (M.add y true env) e || eval_env (M.add y false env) e