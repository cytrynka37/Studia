let append xs ys = 
  match xs with 
  | [] -> ys
  | x : xs -> x :: (append xs ys)}

  Pokaż, że funkcja append zawsze oblicza się do wartości, tzn. pokaż,
że dla dowolnych list xs i ys istnieje lista zs taka, że append xs ys ≡ zs.

1. Baza indukcji
Pokażę, że dla dowolnej listy ys append [] ys = zs

append [] ys
== (Z definicji append)
ys = zs

2. Krok indukcji
Załóżmy, że dla dowolnych list xs, ys, append xs ys = zs.
Pokażę, że append (x :: xs) ys = zs`

append (x :: xs) ys
== (Z definicji append)
x :: append xs ys
== (Z założenia indukcyjnego)
x :: zs = zs`

Co kończy dowód.
