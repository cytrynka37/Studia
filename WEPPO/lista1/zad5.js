function recFib(n) {
    if (n <= 1) return n;
    return recFib(n - 2) + recFib(n - 1);
}

function iterFib(n) {
    if (n <= 1) return n;
    let a = 0, b = 1;
    for (let i = 2; i <= n; i++) {
        [a, b] = [b, a + b];
    }
    return b;
}

function fibTimes(max_n) {
        for (let n = 10; n <= max_n; n++) {
        console.log(n);
        
        console.time('iter');           
        iterFib(n);          
        console.timeEnd('iter');         

        console.time('rec');
        recFib(n);
        console.timeEnd('rec');           
    }
}

fibTimes(40);