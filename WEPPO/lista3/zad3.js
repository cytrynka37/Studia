function createFs(n) { // tworzy tablicę n funkcji
    var fs = []; // i-ta funkcja z tablicy ma zwrócić i
    for ( let i = 0; i < n; i++ ) {
        fs[i] =
            function() {
                return i;
            };
    };
    return fs;
}

function createFs2(n) {
    var fs = [];
    for (var i = 0; i < n; i++) {
        fs[i] = (function(x) {
            return function() {
                return x;
            };
        })(i); // Wywołujemy natychmiast, przekazując aktualną wartość i
    }
    return fs;
}

var myfs = createFs(10);
console.log( myfs[0]() ); // zerowa funkcja miała zwrócić 0
console.log( myfs[2]() ); // druga miała zwrócić 2
console.log( myfs[7]() );
// 10 10 10 // ale wszystkie zwracają 10!?

var myfs = createFs2(10);
console.log(myfs[0]()); // 0
console.log(myfs[2]()); // 2
console.log(myfs[7]()); // 7
