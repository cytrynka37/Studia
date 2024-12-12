console.log(
    (![] + [])[+[]] +
        (![] + [])[+!+[]] +
        ([![]] + [][[]])[+!+[] + [+[]]] +
        (![] + [])[!+[] + !+[]]
);

/*
(![] + [])[+[]]; []
każda lista jest obiektem, co daje true, więc ![] to false
następnie dodajemy pustą tablicę do false, co konwertuje false na tekst,
+[] zamienia pustą tablicę na liczbę, co daje zero, więc mamy ("false")[0], co daje nam "f"
/*

/*
(![] + [])[+!+[]]
'false'[+!+[]] -> +[] daje nam 0, !0 daje nam true, +true daje 1. "false"[1] = "a"
/*

/*
([![]] + [][[]])[+!+[] + [+[]]]
[![]] -> [false]
[][[]] -> indeksujemy pustą listę, gdzie [] w środku jest konwerowane na typ number, w przypadku pustej listy będzie to 0;
[][0] ponieważ próbujemy uzyskać pierwszy element pustej listy, co daje nam undefined
[false] + undefined -> przekształcenie na string, co w sumie daje nam 'falseundefined'
[+!+[] + [+[]]] -> teraz uzyskamy indeks. +!+[] -> +[] to 0, !0 to true, +true daje nam 1.
[+[]] to [0], uzyskujemy więc 1 + [0], następuje konwersja na string, co daje nam 10
ostatecznie 'falseundefined'[10] -> i
/*

/*
(![] + [])[!+[] + !+[]]
![] + [] -> false + [] to 'false'
[!+[] + !+[]] -> !+[] to true, true + true da nam 2 (true jest konwertowane na 1 w kontekście operacji arytemtycznych)
'false'[2] -> 'l'

ostatecznie wszystko dodajemy do siebie i uzyskujemy 'fail'

*/