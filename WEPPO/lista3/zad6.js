function fib() {
    let a = 0, b = 1;
    return {
        next: function() {
            let value = a;
            [a, b] = [b, a + b];
            return { value: value, done: false };
        }
    }
}

function *fib2() {
    let a = 0, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

var it1 = fib();
for (var result; result = it1.next(), !result.done; ) {
    console.log(result.value);
    if (result.value > 100) break;
}

var it2 = fib2();
for (var result; result = it2.next(), !result.done; ) {
    console.log(result.value);
    if (result.value > 100) break;
}

for (var i of fib2()) {
    console.log(i);
    if (i > 100) break;
} // for.. of tylko dla generaora, ponieważ wymaga obiektu iterowalnego, a tylko funkcja generatora automatycznie implementuje Symbol.iterator