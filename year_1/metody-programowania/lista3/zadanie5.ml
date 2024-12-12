type 'a tree = Leaf | Node of 'a tree * 'a * 'a tree

let t =
  Node (Node (Leaf, 2, Leaf),
        5,
        Node (Node (Leaf, 6, Leaf),
              8,
              Node (Leaf, 9, Leaf)))

let rec insert_bst a t = 
  match t with
  | Leaf -> Node(Leaf, a, Leaf)
  | Node (l, v, r) -> if a < v then Node(insert_bst a l, v, r) else if a > v then Node(l, v, insert_bst a r) else t