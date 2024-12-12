function Tree(val, left, right) {
    this.left = left;
    this.right = right;
    this.val = val;
   }

Tree.prototype[Symbol.iterator] = function*() {
    yield this.val;
    if ( this.left ) yield* this.left;
    if ( this.right ) yield* this.right;
}

Tree.prototype.bfsIterator = function*() {
    let queue = [this];
    while (queue.length > 0) {
        let node = queue.splice(0, 1)[0];
        yield node.val;

        if (node.left) queue.push(node.left);
        if (node.right) queue.push(node.right);
    }
}

var root = new Tree( 1, new Tree( 2, new Tree( 3 ),  ), new Tree( 4 ));

console.log("w głąb: ");
for ( var e of root ) {
    console.log(e);
}

console.log("wszerz: ");
for (let e of root.bfsIterator()) {
    console.log(e);
}

/* stos - dodajemy i zdejmujemy elementy z końca.
wyglądałoby więc to tak:
zaczynamy od 1, dodajemy 2 i 4 do stosu, wyjmujemy 4, nastepnie wyjmujemy 2 i dodajemy 3, wyjmujemy 3: 1, 4, 2, 3 
Tree.prototype.dfsIterator = function*() {
    // Stos przechowujący węzły do przetworzenia, początkowo zawiera korzeń drzewa
    let stack = [this];

    // Dopóki stos nie jest pusty
    while (stack.length > 0) {
        // Usuwamy węzeł z końca stosu
        const node = stack.pop();
        
        // Zwracamy (yield) wartość bieżącego węzła
        yield node.val;
        
        // Dodajemy do stosu najpierw prawego, potem lewego syna (jeśli istnieją)
        // Dzięki temu lewy syn zostanie przetworzony pierwszy
        if (node.right) stack.push(node.right);
        if (node.left) stack.push(node.left);
    }
};*/