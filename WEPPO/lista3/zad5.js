function createGenerator(max_value) {
    var _state = 0;
    return {
        next : function() {
            return {
                value : _state,
                done : _state++ >= max_value
            }
        }
    }
}

var foo = {
    [Symbol.iterator] : function() { return createGenerator(5); }
};

for ( var f of foo )
    console.log(f);

var foo2 = {
    [Symbol.iterator] : function() { return createGenerator(15); }
};

for ( var f of foo2 )
    console.log(f);