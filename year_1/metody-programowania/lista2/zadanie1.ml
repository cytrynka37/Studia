let rec fib n =
  if n = 0 then 0
  else if n = 1 then 1
  else fib (n - 1) + fib (n - 2)

  (* fib 4 = fib 3 + fib 2 =
  fib 2 + fib 1 + fib 1 + fib 0 =
  fib 1 + fib 0 + 1 + 1 + 0 =
  1 + 0 + 1 + 1 + 0 = 3 *)

let fib_iter n =
  let rec fib_helper n a b =
    if n = 0 then a
    else fib_helper (n - 1) b (a + b)
  in
  fib_helper n 0 1

  (* fib 4 = fib_helper 4 0 1 =
  fib_helper 3 1 1 = 
  fib_helper 2 1 2 =
  fib_helper 1 2 3 =
  fib_helper 0 3 5 = 3 *)