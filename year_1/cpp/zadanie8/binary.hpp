#pragma once
#include "unary.hpp"

class Binary : public Unary{
    protected:
        Expression *expr2;
    
    public:
        Binary(Expression *expr, Expression *expr2);
};

class Add : public Binary{
    public:
        Add(Expression *expr, Expression *expr2);
        double evaluate() const override;
        std::string to_string() const override;
};

class Sub : public Binary{
    public:
        Sub(Expression *expr, Expression *expr2);
        double evaluate() const override;
        std::string to_string() const override;
};

class Mult : public Binary{
    public:
        Mult(Expression *expr, Expression *expr2);
        double evaluate() const override;
        std::string to_string() const override;
};

class Div : public Binary{
    public:
        Div(Expression *expr, Expression *expr2);
        double evaluate() const override;
        std::string to_string() const override;
};

class Pow : public Binary{
    public:
        Pow(Expression *expr, Expression *expr2);
        double evaluate() const override;
        std::string to_string() const override;
};

class Mod : public Binary{
    public:
        Mod(Expression *expr, Expression *expr2);
        double evaluate() const override;
        std::string to_string() const override;
};

class Log : public Binary{
    public:
        Log(Expression *expr, Expression *expr2);
        double evaluate() const override;
        std::string to_string() const override;
};

