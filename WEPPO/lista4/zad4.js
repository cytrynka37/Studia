var n = 1;

// liczba ma prototyp?
console.log( typeof Object.getPrototypeOf( n ) );

// można jej dopisać pole/funkcję?
n.foo = 'foo';
console.log( n.foo );

/*
Typy proste same w sobie nie mają prototypu, jednak JS tworzy tymczasowy obiekt typu opakowującego (Number), aby umożliwić dostęp
do właściwości i metod typowych, w tym przypadku, dla liczb. Dlatego dostajemy prototyp obiektu Number -> "object"

Ale wartości typów prostych nie są obiektami, więc nie możemy przypisywać ich nowych właściwości - dlatego nie uda nam się dopisać
nowego pola.
*/