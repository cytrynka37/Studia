let rec min xs =
  match xs with
  | [] -> failwith "empty"
  | x::[] -> x
  | x::y -> let m = min y in if x > m then m else x


let select xs =
  let rec __select x xs =
    match xs with
    | [] -> []
    | a::b -> if x = a then b else a::(__select x b)
  in let m = min xs
in (m, __select m xs)

let rec select_sort xs =
  match xs with
  | [] -> []
  | _ -> let (m, rest) = select xs in m :: select_sort rest