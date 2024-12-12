let rec suffixes xs =
  match xs with
  | [] -> [[]]
  | hd :: tl -> xs :: suffixes tl

(*Funkcja suffixes jest zdefiniowana rekurencyjnie. Oznacza to, że dla pustej listy xs zwracamy listę zawierającą jedyny element - pustą listę [], 
która jest sufiksem każdej listy. Jest to przypadek bazowy rekursji.

Gdy lista xs nie jest pusta (hd :: tl), co oznacza, że ma co najmniej jeden element, dodajemy pełną listę xs do wyniku. Jest to główna część funkcji. 
Następnie rekurencyjnie wywołujemy suffixes na ogonie listy tl, aby znaleźć sufiksy pozostałych elementów listy, i dodajemy je do wyniku.

Rekursja kontynuuje się, aż do momentu, gdy xs jest pustą listą, co prowadzi do zakończenia wywołań rekurencyjnych i zwrócenia wyniku.

W efekcie funkcja suffixes generuje wszystkie sufiksy listy xs, począwszy od pełnej listy i kończąc na pustej liście, zwracając wynik w formie listy list, 
gdzie każda lista reprezentuje jeden sufiks.*)