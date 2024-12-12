let empty_set = false

let singleton a = fun x -> x = a

let in_set a s = s a

let union s t = fun x -> s x || t x

let intersect s t = fun x -> s x && t x

let zbior = union (singleton 4) (singleton 5)