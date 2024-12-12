#pragma once
#include "expression.hpp"
#include <sstream>

class Number : public Expression{
    private:
        double value;
    
    public:
    Number(double val) : value(val) {}
    double evaluate() const override { return value; };
    std::string to_string() const override { 
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
};