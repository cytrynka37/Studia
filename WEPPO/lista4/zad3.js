var Person = function(name) {
    this.name = "Someone";
   }

var Worker = function() {}

/* dobrze:
var Person = ...
var Worker = ...
Worker.prototype = Object.create( Person.prototype );

sa to oddzielne obiekty, wiec mozna dodawac metody w Worker.prototype bez zmieniania Person.
tworzymy nowy obiekt, który nie zawiera specyficznych wlasciwosci dla instancji Person.

źle:
var Person = ...
var Worker = ...
Worker.prototype = Person.prototype;

Składowe dodane do Worker.prototype będą także dostępne dla Person.prototype*/

Worker.prototype = Person.prototype;

Person.prototype.greet = function() { return "Hello from Person"; };
Worker.prototype.greet = function() { return "Hello from Worker"; };

console.log(new Person().greet());

/*też źle:
var Person = ...
var Worker = ...
Worker.prototype = new Person();

Jezeli konstruktor Person ustawia pewne dane to te wlasciwosci znajda sie rowniez w Worker.prototype,
co jest niepozadane, bo prototyp nie powinein zawierac specyficznych danych dla instanjcji.*/

Worker.prototype = new Person();
const worker1 = new Worker();

console.log(worker1.name);