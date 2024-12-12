#pragma once
#include "expression.hpp"

class Constant : public Expression{
    private:
        double value;
        std::string name;
    
    public:
        Constant(double val, std::string n) : value(val), name(n) {}
        double evaluate() const override { return value; };
        std::string to_string() const override { return name; };
};

class Pi : public Constant{
public:
    Pi() : Constant(3.14159265359, "pi") {}
};

class Fi : public Constant{
public:
    Fi() : Constant(1.61803398875, "fi") {}
};

class e : public Constant{
public:
    e() : Constant(2.71828182846, "e") {}
};