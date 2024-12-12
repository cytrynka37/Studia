var p = {
    name: 'jan'
}

var q = {
    surname: 'kowalski'
}

function isObjectProperty(obj, property) {
    return obj.hasOwnProperty(property);
}

Object.setPrototypeOf( p, q );


console.log("Skladowe obiektu p : ");
for (let property in p) {
    if (isObjectProperty(p, property)) {
        console.log(property + ": " + p[property]);
    }
}

console.log("Skladowe obiektu p i jego prototypu: ");
for (let property in p) {
    console.log(property + ": " + p[property]);
}
