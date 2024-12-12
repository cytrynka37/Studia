let rec mem x xs =
  match xs with
  | [] -> false          (* Jeśli lista jest pusta, element x na pewno nie jest w niej *)
  | a :: b ->          (* Rozpatrujemy głowę i ogon listy *)
    if a = x then       (* Jeśli głowa listy równa się x, to x jest w liście *)
      true
    else
      mem x b