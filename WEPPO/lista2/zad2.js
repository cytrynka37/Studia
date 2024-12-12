const person = {
    name: "Jan",
    age: 37,
    "home town": "Wrocław"
};

console.log(person.name);
console.log(person["name"]);

console.log(person["home town"]);
/* console.log(person.home town); - tak nie można, podobnie znaki specjalne */

person[42] = "wartość";
console.log(person[42]); // liczba jest konwertowana na string, person[42] jest tym samym co person["42"]
console.log(person);

const keyObject = { a: 1 };
person[keyObject] = "wartość dla obiektu"; // js konwertuje obiekt na ciąg znaków wywołując toString(), co domyślnie zwraca [object Object]
console.log(person["[object Object]"]); // 'wartość dla obiektu'; 
console.log(person);

const arr = [1, 7, 9];
arr["text"] = "something"

console.log(arr);
console.log(arr["text"]);
console.log(arr.length);

arr.length = 5;
console.log(arr.length);
console.log(arr); 

arr.length = 2;
console.log(arr.length);
console.log(arr); 