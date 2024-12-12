let split xs =
  let rec __split xs f n =
    if n = 0 
      then (f, xs)
  else __split (List.tl xs) ((List.hd xs)::f) (n-1)
in __split xs [] ((List.length xs)/2)

let rec merge xs ys =
  match xs, ys with
  | [], _ -> ys
  | _, [] -> xs
  | x::xs', y::ys' ->
    if x <= y then
      x :: merge xs' ys
    else
      y :: merge xs ys'

let rec merge_sort xs = 
  match xs with
  | [] -> []
  | [x] -> [x]
  | _ -> let (l, r) = split xs in
  let r_sorted = merge_sort r in
  let l_sorted = merge_sort l in
  merge l_sorted r_sorted

  (*procedura merge_sort jest strukturalnie rekurencyjna. Strukturalna rekurencja odnosi się do rekurencji, gdzie każde wywołanie rekurencyjne 
  jest na strukturze danych o mniejszym rozmiarze niż struktura danych wejściowych. W przypadku merge_sort, w każdym wywołaniu rekurencyjnym 
  dzielimy listę na pół (lub na zbliżoną do pół listę) za pomocą funkcji split, co prowadzi do powstania dwóch list o połowicznym rozmiarze. 
  Następnie rekurencyjnie sortujemy te dwie połowy.

  Ponieważ rozmiar każdej z tych dwóch połówek jest mniejszy niż rozmiar oryginalnej listy, to procedura merge_sort spełnia warunek strukturalnej rekurencji.

  Dzięki temu procedura merge_sort będzie zbieżna i ostatecznie zakończy swoje działanie, ponieważ w każdym kroku redukuje rozmiar problemu, aż do osiągnięcia  
  przypadku bazowego, którym są jednoelementowe listy.*)