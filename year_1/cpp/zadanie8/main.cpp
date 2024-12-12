#include <iostream>
#include "number.hpp"
#include "constant.hpp"
#include "variable.hpp"
#include "unary.hpp"
#include "binary.hpp"
#include <iomanip>

int main(){
    Expression *expr = 
    new Sub(
        new Pi(), 
        new Add(
            new Number(2), 
            new Mult(
                new Variable("x"), 
                new Number(7)
                )
            )
        );

    Expression *expr1 = 
    new Div(
        new Mult(
            new Sub(
                new Variable("x"), 
                new Number(1)), 
            new Variable("x")
            ), 
        new Number(2)
        );
    
    Expression *expr2 = 
    new Div(
        new Add(
            new Number(3), 
            new Number(5)
            ), 
        new Add(
            new Number(2),
            new Mult(
                new Variable("x"), 
                new Number(7)
                )
            )
        );
    
    Expression *expr3 =
    new Sub(
        new Add(
            new Number(2), 
            new Mult(
                new Variable("x"), 
                new Number(7)
                )
            ),
        new Add(
            new Mult(
                new Variable("y"),
                new Number(3)
                ),
            new Number(5)
            )
        );
    
    Expression *expr4 =
    new Div(
        new Cos(
            new Mult(
                new Add(
                    new Variable("x"),
                    new Number(1)
                ),
                new Pi()
            )
        ),
        new Pow(
            new e(),
            new Pow(
                new Variable("x"),
                new Number(2)
            )
        )
    );

    std::cout << expr->to_string() << std::endl;
    std::cout << expr1->to_string() << std::endl;
    std::cout << expr2->to_string() << std::endl;
    std::cout << expr3->to_string() << std::endl;
    std::cout << expr4->to_string() << std::endl;
    
    Variable::addVariable("x", 0);
    Variable::addVariable("y", 0);

    for (double i = 0; i <= 1; i += 0.1){
        Variable::changeVariable("x", i);
        Variable::changeVariable("y", i);
        std::cout << "x = " << i << ", y = " << i << std::endl;
        std::cout << "Wyrażenie 1: " << std::setprecision(10) << expr1->evaluate() << std::endl;
        std::cout << "Wyrażenie 2: " << expr2->evaluate() << std::endl;
        std::cout << "Wyrażenie 3: " << expr3->evaluate() << std::endl;
        std::cout << "Wyrażenie 4: " << expr4->evaluate() << std::endl;
    }
}