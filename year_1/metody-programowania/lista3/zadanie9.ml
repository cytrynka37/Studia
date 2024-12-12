type 'a tree = Leaf | Node of 'a tree * 'a * 'a tree

let t =
  Node (Node (Leaf, 2, Leaf),
        5,
        Node (Node (Leaf, 6, Leaf),
              8,
              Node (Leaf, 9, Leaf)))
let rec find_node t =
    match t with
    | Leaf -> 0
    | Node (Leaf, v, _) -> v
    | Node (l, v, r) -> find_node l

let rec delete t a =
  match t with
  | Leaf -> Leaf
  | Node (l, v, r) -> if a > v then Node(l, v, delete r a)
  else if a < v then Node(delete l a, v, r)
  else match (l, r) with
  | (Leaf, r) -> r
  | (l, Leaf) -> l
  | _ -> let min = find_node r in Node(l, min, delete r min)