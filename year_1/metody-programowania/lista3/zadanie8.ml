type 'a tree = Leaf | Node of 'a tree * 'a * 'a tree


let rec fold_tree f a t =
  match t with
  | Leaf -> a
  | Node (l, v, r) -> f (fold_tree f a l) v (fold_tree f a r)

let t =
  Node (Node (Leaf, 2, Leaf),
        5,
        Node (Node (Leaf, 6, Leaf),
              8,
              Node (Leaf, 9, Leaf)))

let rec insert_bst a t = 
  match t with
  | Leaf -> Node(Leaf, a, Leaf)
  | Node (l, v, r) -> if a < v then Node(insert_bst a l, v, r) else Node(l, v, insert_bst a r)


  let inorder t = fold_tree (fun l v r -> l @ [v] @ r) [] t 

  let tree_sort xs =
    let rec build_tree xs tree =
      match xs with
      | [] -> tree
      | hd :: tl -> build_tree tl (insert_bst hd tree)
    in inorder (build_tree xs Leaf)