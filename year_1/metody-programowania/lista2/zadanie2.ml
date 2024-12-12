(*mnozenie macierzy*)
let m = (42, 1, 4, 9)
let n = (4, 1, 9, 2)
let matrix_mult m n = let a, b, c, d = m in let e, f, g, h = n in (a * e + b * g, a * f + b * h, c * e + d * g, c * f + d * h)

(*macierz identycznosciowa*)
let matrix_id = (1, 0, 0, 1);;

(*mnozenie macierzy*)
let rec matrix_expt m k =
  if k = 0 then matrix_id
  else if k = 1 then m
  else matrix_mult m (matrix_expt m (k-1))

(*fibonacci*)
let fib_matrix k =
  let m = (1, 1, 1, 0) in
  let fib_matrix_k = matrix_expt m k in 
  match fib_matrix_k with
  | (_, f_k, _, _) -> f_k