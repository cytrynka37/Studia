function filter<T>(a: T[], f: (t: T) => boolean): T[] {
    const result = new Array<T>;
    for (let i of a) {
        if (f(i)) result.push(i);
    }
    return result;
}

function map<T, S>(a: T[], f: (t: T) => S): S[] {
    const result = new Array<S>;
    for (let i of a) {
        result.push(f(i));
    }
    return result; 
}

function forEach<T>(a: T[], action: (arg: T) => void): void {
    for (let i = 0; i < a.length; i++) {
        action(a[i]);
    }
}

const numbers = [1, 2, 3, 4, 5];
console.log(filter(numbers, (n) => n % 2 === 0));

const strings = ["1", "2", "3"];
const numbersFromString = map(strings, (s) => parseInt(s, 10));
console.log(numbersFromString);

numbers.forEach(function (value) {
    console.log(value);
});