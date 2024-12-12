#pragma once
#include <string>

class Expression{
    public:
        virtual double evaluate() const = 0;
        virtual std::string to_string() const = 0;
        Expression() = default;
        virtual ~Expression() = default;
        Expression(const Expression&) = delete;
        Expression& operator=(const Expression&) = delete;
        Expression(Expression&&) = delete;
        Expression& operator=(Expression&&) = delete;
};