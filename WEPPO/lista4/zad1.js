function getLastProto(o) {
    var p = o;
    do {
        o = p;
        p = Object.getPrototypeOf(o);
    } while (p);
    return o;
}

const obj1 = {};
const arr1 = [];
const func1 = function() {};
const date1 = new Date();

console.log(getLastProto(obj1) === getLastProto(arr1));
console.log(getLastProto(obj1) === getLastProto(func1));
console.log(getLastProto(obj1) === getLastProto(date1));
