type 'a tree = Leaf | Node of 'a tree * 'a * 'a tree

let rec fold_tree f a t =
  match t with
  | Leaf -> a
  | Node (l, v, r) -> f (fold_tree f a l) v (fold_tree f a r)

let tree_product t = fold_tree (fun l v r -> v * l * r) 1 t

let tree_flip t =
  let flip_node l v r = Node (r, v, l) in
  fold_tree flip_node Leaf t

let tree_height t =
  let max_height l v r = 1 + (if l > r then l else r) in
  fold_tree max_height 0 t

  let tree_span t = 
    match t with
    | Leaf -> (0,0)
    | Node(l, v, r) -> 
      let tree_min t = fold_tree (fun l v r -> min (min l r) v ) v t in 
      let tree_max t = fold_tree (fun l v r -> max (max l r) v ) v t in
      ((tree_min t), (tree_max t));;
  

let preorder t = fold_tree (fun l v r -> v :: l @ r) [] t 

let example_tree = Node (Node (Leaf, 2, Leaf), 3, Node(Leaf, 4, Leaf))

let t =
  Node (Node (Leaf, 2, Leaf),
        5,
        Node (Node (Leaf, 6, Leaf),
              8,
              Node (Leaf, 9, Leaf)))
