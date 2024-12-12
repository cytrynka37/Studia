function memoFib() {
    var memo = {};
    return function fib(n) {
        if (n in memo) return memo[n];
        if (n <= 1) return n;
        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    };
}

function recFib(n) {
    if (n <= 1) return n;
    return recFib(n - 1) + recFib(n - 2);
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
    const mf = memoFib();
    for (let n = 10; n <= max_n; n++) {
        console.log(`Calculating fib(${n}):`);
        
        console.time('iter');           
        iterFib(n);          
        console.timeEnd('iter');         

        console.time('rec');
        recFib(n);
        console.timeEnd('rec');           
        
        console.time('memo');
        mf(n);
        console.timeEnd('memo');     
    }
}

fibTimes(40);
