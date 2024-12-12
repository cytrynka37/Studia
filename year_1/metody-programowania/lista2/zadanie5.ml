let maximum xs =
  let rec find_max max xs =
    match xs with
    | [] -> max
    | a :: b ->
      if a > max then find_max a b
      else find_max max b
  in
  match xs with
  | [] -> neg_infinity
  | a :: b -> find_max a b
