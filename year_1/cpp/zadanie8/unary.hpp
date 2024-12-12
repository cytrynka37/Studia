#pragma once
#include "expression.hpp"
#include <cmath>

class Unary : public Expression{
    protected:
        Expression *expr;
    public:
        Unary(Expression *expr);
};

class Sin : public Unary{
    public:
        Sin(Expression *expr);
        double evaluate() const override;
        std::string to_string() const override;
};

class Cos : public Unary{
    public:
        Cos(Expression *expr);
        double evaluate() const override;
        std::string to_string() const override;
};

class Exp : public Unary{
    public:
        Exp(Expression *expr);
        double evaluate() const override;
        std::string to_string() const override;
};

class Ln : public Unary{
    public:
        Ln(Expression *expr);
        double evaluate() const override;
        std::string to_string() const override;
};

class Abs : public Unary{
    public:
        Abs(Expression *expr);
        double evaluate() const override;
        std::string to_string() const override;
};

class Negate : public Unary{
    public:
        Negate(Expression *expr);
        double evaluate() const override;
        std::string to_string() const override;
};

class Reciprocal : public Unary{
    public:
        Reciprocal(Expression *expr);
        double evaluate() const override;
        std::string to_string() const override;
};
