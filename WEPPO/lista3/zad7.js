function* fib() {
    let a = 0, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

function* take(it, top) {
    let counter = 0;
    for (let value of it) {
        if (counter++ >= top) {
            return;
        }
        yield value;
    }
}

for (let num of take(fib(), 10)) {
    console.log(num);
}