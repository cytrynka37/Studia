module type DICT = sig
  type ('a, 'b) dict
  val empty : ('a, 'b) dict
  val insert : 'a -> 'b -> ('a, 'b) dict -> ('a, 'b) dict
  val remove : 'a -> ('a, 'b) dict -> ('a, 'b) dict
  val find_opt : 'a -> ('a, 'b) dict -> 'b option
  val find : 'a -> ('a, 'b) dict -> 'b
  val to_list : ('a, 'b) dict -> ('a * 'b) list
end

module ListDict : DICT = struct
  type ('a, 'b) dict = ('a * 'b) list
  let empty = []
  let remove k d = List.filter (fun (k', _) -> k <> k') d
  let insert k v d = (k, v) :: remove k d
  let find_opt k d = List.find_opt (fun (k', _) -> k = k') d |> Option.map snd
  let find k d = List.find (fun (k', _) -> k = k') d |> snd
  let to_list d = d
end

module type PRIO_QUEUE = sig
  type ('a, 'b) pq
  
  val empty : ('a, 'b) pq
  val insert : 'a -> 'b -> ('a, 'b) pq -> ('a, 'b) pq
  val pop : ('a, 'b) pq -> ('a, 'b) pq
  val min_with_prio : ('a, 'b) pq -> 'a * 'b
end

module ListPrioQueue : PRIO_QUEUE = struct
  type ('a, 'b) pq = ('a * 'b) list

  let empty = []
  let rec insert a x q = match q with
  | [] -> [a, x]
  | (b, y) :: ys -> if a < b then (a, x) :: q else (b, y) :: insert a x ys
  let pop q = List.tl q
  let min_with_prio q = List.hd q
end

module type HUFFMAN = sig
  type 'a code_tree
  type 'a code_dict
  val code_tree : 'a list -> 'a code_tree
  val dict_of_code_tree : 'a code_tree -> 'a code_dict
  val encode : 'a list -> 'a code_dict -> int list
  val decode : int list -> 'a code_tree -> 'a list
end


module HuffmanF (Dict: DICT) (PrioQueue : PRIO_QUEUE) : HUFFMAN = struct
  type 'a code_tree = CTNode of 'a code_tree * 'a code_tree | CTLeaf of 'a
  type 'a code_dict = ('a, int list) Dict.dict

  let find_else x a d = Option.value ~default:0 (Dict.find_opt x d)

  let freq_dict xs =
    let rec it xs d =
      match xs with
      | [] -> d
      | x :: xs' -> 
        it xs' (Dict.insert x 
                  (1 + find_else x 0 d) d)
    in it xs Dict.empty

  let initial_pq xs =
    List.fold_left (fun q (x, n) -> PrioQueue.insert n (CTLeaf x) q)
      PrioQueue.empty xs
    
  let rec algo q =
    let p1, t1 = PrioQueue.min_with_prio q
    and q1 = PrioQueue.pop q
    in if q1 = PrioQueue.empty then t1
    else let p2, t2 = PrioQueue.min_with_prio q1
    and q2 = PrioQueue.pop q1
    in algo (PrioQueue.insert (p1 + p2) (CTNode (t1, t2)) q2)     

  let make_code_tree d = Dict.to_list d |> initial_pq |> algo
  let code_tree a = a |> freq_dict |> make_code_tree
  let dict_of_code_tree t =
    let rec aux t rcpref d =
      match t with
      | CTLeaf x -> Dict.insert x (List.rev rcpref) d
      | CTNode (l, r) -> aux l (0 :: rcpref) (aux r (1 :: rcpref) d)
    in aux t [] Dict.empty


  let encode xs d =
    List.fold_right (@) (List.map (fun x -> Dict.find x d) xs) [] 

  let decode bs t =
    let rec walk bs cur_t =
      match cur_t with
      | CTLeaf v -> v :: start bs
      | CTNode (l, r) ->
        match bs with
        | 0 :: bs' -> walk bs' l
        | 1 :: bs' -> walk bs' r
        | _ :: _ -> failwith "a value other than 0 or 1 encountered"
        | [] -> failwith "incomplete code"
    and start bs =
      if bs = [] then [] else walk bs t
    in start bs    
end

  let list_of_string s = String.to_seq s |> List.of_seq

  module Huffman = HuffmanF (ListDict) (ListPrioQueue)

  let s = "abcder"
  let tree = Huffman.code_tree (list_of_string s)
  let dict = Huffman.dict_of_code_tree tree  
  let encoded = Huffman.encode (list_of_string s) dict  

  let decoded = Huffman.decode encoded tree  
