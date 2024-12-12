let rec build_list n f =
  if n <= 0 then
    []
  else
    (f 0) :: build_list (n - 1) (fun x -> f (x + 1))

let negatives n = build_list n (fun x -> -x - 1)
let reciprocals n = build_list n (fun x -> 1.0 /. float_of_int (x + 1))
let evens n = build_list n (fun x -> 2 * x)
let identityM n =
  build_list n (fun x -> build_list n (fun y -> if x = y then 1 else 0))
  
