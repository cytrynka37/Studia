let is_sorted xs =
  let rec acc_is_sorted x xs =
    match xs with
    | [] -> true
    | a :: b -> if a > x then false
    else acc_is_sorted a b
  in
  match xs with
  | [] -> true
  | a :: b -> acc_is_sorted a b

 
Deklaracja funkcji is_sorted xs, która przyjmuje listę xs.
Wewnątrz tej funkcji definiujemy pomocniczą funkcję rekurencyjną acc_is_sorted, która będzie sprawdzać posortowanie, biorąc pod uwagę elementy od drugiego do ostatniego. Funkcja ta przyjmuje dwa argumenty: x, który jest poprzednim elementem, oraz xs, które są kolejnymi elementami do sprawdzenia.
W funkcji acc_is_sorted używamy dopasowania wzorca (pattern matching) do sprawdzenia, czy lista xs jest pusta. Jeśli lista jest pusta ([]), to oznacza, że doszliśmy do końca listy i zwracamy true, co oznacza, że wszystkie elementy były w porządku.
Jeśli lista nie jest pusta (a :: b), czyli składa się z głowy a i ogona b, to sprawdzamy, czy a (aktualny element) jest większy niż x (poprzedni element). Jeśli tak, to lista nie jest posortowana, zwracamy false. W przeciwnym przypadku rekurencyjnie wywołujemy funkcję acc_is_sorted, przechodząc do następnego elementu a i ogona b.
Po zdefiniowaniu funkcji acc_is_sorted, w głównej funkcji is_sorted używamy ponownie dopasowania wzorca, aby sprawdzić, czy lista xs jest pusta czy też nie.
Jeśli lista jest pusta ([]), to oznacza, że lista jest posortowana, więc zwracamy true.
Jeśli lista nie jest pusta (a :: b), to wywołujemy funkcję acc_is_sorted, aby sprawdzić, czy lista jest posortowana zaczynając od pierwszego elementu a i ogona b.
Ogólnie rzecz biorąc, ta implementacja sprawdza, czy lista jest posortowana w porządku niemalejącym poprzez porównanie każdego elementu z jego następnikiem, zaczynając od pierwszego elementu. Jeśli żadne dwa kolejne elementy nie są w złej kolejności (tzn. każdy kolejny element jest większy lub równy poprzedniemu), funkcja zwraca true.







