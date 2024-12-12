exception Found

let exists f xs =
  try List.fold_left (fun b x -> if b then raise Found else f x) false xs
with Found -> true

let is_greater_than_10 x = x > 10