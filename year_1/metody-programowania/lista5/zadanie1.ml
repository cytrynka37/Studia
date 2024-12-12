
let rec map f = function
  | [] -> []
  | x :: xs -> f x :: map f xs

let add_one x = x + 1
let numbers = [1; 2; 3; 4; 5]
let incremented_numbers = map add_one numbers

(*Pokaż, że dla dowolnych funkcji f i g oraz listy xs zachodzi map f (map g xs) ≡ map (fun x -> f (g x)) xs
Indukcja po liście xs:
1) Krok bazowy map f (map g []) = map (fun x -> f (g x)) []
Weźmy dowolne f, g, x
L == map f (map g []) == map f [] == []
P == map (fun x -> f (g x)) [] == []
L == P

2) Załóżmy, że map f (map g xs) ≡ map (fun x -> f (g x)) xs. Pokażemy, że dla dowolnego f, g, x: map f (map g x::xs) ≡ map (fun x -> f (g x)) x::xs
map f (map g x::xs) == 
map f (g x :: map g xs) == 
f (g x) :: map f (map g xs) == 
f (g x) :: map (fun x -> f (g x)) xs == 
map (fun x -> f (g x)) x :: xs
*)