function recFib(n : number) : number {
    if (n <= 1) return n;
    return recFib(n - 1) + recFib(n - 2);
}

function memoFib<T>(fn : (arg: T) => T) {
    var memo = new Map<T, T>();
    return function (n : T) {
        if (memo.has(n)) return memo.get(n);
        
        const res = fn(n);
        memo.set(n, res);
        return res;
    };
}

function fibTimes(max_n : number) {
    const mf = memoFib(recFib);
    for (let n = 10; n <= max_n; n++) {
        console.log(`Calculating fib(${n}):`);   

        console.time('rec');
        recFib(n);
        console.timeEnd('rec');           
        
        console.time('memo');
        mf(n);
        console.timeEnd('memo');     
    }
}

fibTimes(45);