var Foo = (function () {
    function Foo() {}

    function Qux() {
        console.log("Foo::Qux");
    }
    
    Foo.prototype.Bar = function() {
        console.log("Foo::Bar");
        Qux();
    };

    return Foo;
}());

const foo = new Foo();

foo.Bar(); 
console.log(typeof foo.Qux); 
