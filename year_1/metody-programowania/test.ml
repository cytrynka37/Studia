let ( let* ) xs ys = List.concat_map ys xs

let rec choose m n =
  if m > n then [] else m :: choose (m+1) n


let rec help bl len =
  if len > 0 then bl :: (help bl (len - 1)) else []

  let rec build_row ps n =
    let rec __build_row ps n curr tab =
      match ps with
      | [] -> [tab @ help false (n - curr)]
      | head::[] -> let* a = choose curr (n - 1) in
        if n >= a + head then [tab @ help false (a - curr) @ help true head @ help false (n - a - head)] else []
      | head::tail -> let* a = choose curr (n - 1) in 
        if n >= a + head 
            then let* b = choose (a + head) (n - 1) in
              __build_row tail n (b + 1) (tab @ help false (a - curr) @ help true head @ help false (b + 1 - a - head)) else []
    in
    let rec remove_duplicates acc = function
      | [] -> acc
      | x :: xs -> if List.mem x acc then remove_duplicates acc xs else remove_duplicates (x :: acc) xs
    in
    remove_duplicates [] (__build_row ps n 0 [])
  
let rec build_candidate pss n =
  let rec __build_candidate spec n acc =
    match spec with
    | [] -> [acc]
    | head :: tail ->
      let candidates = build_row head n in
      let valid_candidates = List.filter (fun x -> List.length x = n) candidates in
      let new_acc = List.concat_map (fun x -> __build_candidate tail n (acc @ [x])) valid_candidates in
      new_acc
  in
  __build_candidate pss n []


let verify_row ps xs = 
  let rec __verify_row xs curr acc = 
    match xs with
    | [] -> if curr > 0 then curr :: acc else acc
    | true::tail -> __verify_row tail (curr + 1) acc
    | false::tail -> __verify_row tail 0 (if curr > 0 then curr :: acc else acc)
  in __verify_row xs 0 [] = List.rev(ps)

  
let rec verify_rows pss xss =
  match pss, xss with
  | [], [] -> true
  | [], _ -> false
  | _, [] -> false
  | pssh::psst, xssh::xsst -> if verify_row pssh xssh then verify_rows psst xsst else false

let rec transpose pss =
  match pss with
  | [] -> []
  | []::_ -> []
  | _ ->
      let head_column = List.map List.hd pss in
      let tail = List.map List.tl pss in
      head_column :: transpose tail
  
type nonogram_spec = {rows: int list list; cols: int list list}

let solve_nonogram nono =
  build_candidate (nono.rows) (List.length (nono.cols))
  |> List.filter (fun xss -> transpose xss |> verify_rows nono.cols)

let test = [[1;2];[1;1]]
  let example_1 = {
  rows = [[2];[1];[1]];
  cols = [[1;1];[2]]
}

let example_2 = {
  rows = [[2];[2;1];[1;1];[2]];
  cols = [[2];[2;1];[1;1];[2]]
}

let big_example = {
  rows = [[1;2];[2];[1];[1];[2];[2;4];[2;6];[8];[1;1];[2;2]];
  cols = [[2];[3];[1];[2;1];[5];[4];[1;4;1];[1;5];[2;2];[2;1]]
}
