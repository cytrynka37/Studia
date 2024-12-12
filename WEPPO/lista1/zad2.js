function isSelfDividing(number) {
    let digits = Array.from(String(number), Number);
    let sum_of_digits = digits.reduce( (sum, digit) => sum + digit);

    for (let digit of digits) {
        if (number % digit !== 0)
            return false;
    }

    return number % sum_of_digits == 0;
}

function getSelfDividingNumbers(n=100000) {
    for (let i = 1; i <= n; i++) {
        if (isSelfDividing(i))
            console.log(i);
    }
}

getSelfDividingNumbers();
