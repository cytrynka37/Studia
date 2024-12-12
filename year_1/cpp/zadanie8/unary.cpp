#include "unary.hpp"

Unary::Unary(Expression *expr) : expr(expr) {}

Sin::Sin(Expression *expr) : Unary(expr) {}

double Sin::evaluate() const {
    return sin(expr->evaluate());
}

std::string Sin::to_string() const {
    return "sin(" + expr->to_string() + ")";
}

Cos::Cos(Expression *expr) : Unary(expr) {}

double Cos::evaluate() const {
    return cos(expr->evaluate());
}

std::string Cos::to_string() const {
    return "cos(" + expr->to_string() + ")";
}

Exp::Exp(Expression *expr) : Unary(expr) {}

double Exp::evaluate() const {
    return exp(expr->evaluate());
}

std::string Exp::to_string() const {
    return "exp(" + expr->to_string() + ")";
}

Ln::Ln(Expression *expr) : Unary(expr) {}

double Ln::evaluate() const {
    return log(expr->evaluate());
}

std::string Ln::to_string() const {
    return "ln(" + expr->to_string() + ")";
}

Abs::Abs(Expression *expr) : Unary(expr) {}

double Abs::evaluate() const {
    return fabs(expr->evaluate());
}

std::string Abs::to_string() const {
    return "| " + expr->to_string() + " |";
}

Negate::Negate(Expression *expr) : Unary(expr) {}

double Negate::evaluate() const {
    return -expr->evaluate();
}

std::string Negate::to_string() const {
    return "-(" + expr->to_string() + ")";
}

Reciprocal::Reciprocal(Expression *expr) : Unary(expr) {}

double Reciprocal::evaluate() const {
    return 1.0 / expr->evaluate();
}

std::string Reciprocal::to_string() const {
    return "(1 / " + expr->to_string() + ")";
}
