function isPrime(x) {
    if (x < 2) return false;
    if (x == 2) return true;
    for (let i = 2; i <= Math.sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

function getPrimeNumbers(a = 2, b = 100000) {
    for (let i = a; i <= b; i++) {
        if (isPrime(i)) console.log(i);
    }
} 

getPrimeNumbers();