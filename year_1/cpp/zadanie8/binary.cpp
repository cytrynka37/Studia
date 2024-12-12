#include "binary.hpp"
#include "iostream"

Binary::Binary(Expression *expr, Expression *expr2) : Unary(expr), expr2(expr2) {}

Add::Add(Expression *expr, Expression *expr2) : Binary(expr, expr2) {}

Sub::Sub(Expression *expr, Expression *expr2) : Binary(expr, expr2) {}

Mult::Mult(Expression *expr, Expression *expr2) : Binary(expr, expr2) {}

Div::Div(Expression *expr, Expression *expr2) : Binary(expr, expr2) {}

Pow::Pow(Expression *expr, Expression *expr2) : Binary(expr, expr2) {}

Mod::Mod(Expression *expr, Expression *expr2) : Binary(expr, expr2) {}

Log::Log(Expression *expr, Expression *expr2) : Binary(expr, expr2) {}

double Add::evaluate() const{
    return expr->evaluate() + expr2->evaluate();
}

std::string Add::to_string() const {
    return expr->to_string() + " + " + expr2->to_string();
}

double Sub::evaluate() const {
    return expr->evaluate() - expr2->evaluate();
}

std::string Sub::to_string() const {
    std::string leftStr = expr->to_string();
    std::string rightStr = expr2->to_string();
    if (dynamic_cast<Add*>(expr2) != nullptr || dynamic_cast<Sub*>(expr2) != nullptr) {
        rightStr = "(" + rightStr + ")";
    }
    return leftStr + " - " + rightStr;
}

double Mult::evaluate() const {
    return expr->evaluate() * expr2->evaluate();
}

std::string Mult::to_string() const {
    std::string leftStr = expr->to_string();
    std::string rightStr = expr2->to_string();
    if (dynamic_cast<Add*>(expr) != nullptr || dynamic_cast<Sub*>(expr) != nullptr) {
        leftStr = "(" + leftStr + ")";
    }
    if (dynamic_cast<Add*>(expr2) != nullptr || dynamic_cast<Sub*>(expr2) != nullptr) {
        rightStr = "(" + rightStr + ")";
    }
    return leftStr + " * " + rightStr;
}


double Div::evaluate() const {
    double right = expr2->evaluate();
    if (right == 0){
        throw std::invalid_argument("Nie mozna dzielic przez 0!");
    }
    return expr->evaluate() / right;
}

std::string Div::to_string() const {
    std::string leftStr = expr->to_string();
    std::string rightStr = expr2->to_string();
    if (dynamic_cast<Add*>(expr) != nullptr || dynamic_cast<Sub*>(expr) != nullptr || dynamic_cast<Mult*>(expr) != nullptr) {
        leftStr = "(" + leftStr + ")";
    }
    if (dynamic_cast<Add*>(expr2) != nullptr || dynamic_cast<Sub*>(expr2) != nullptr || dynamic_cast<Mult*>(expr2) != nullptr ||
        dynamic_cast<Div*>(expr2) != nullptr) {
        rightStr = "(" + rightStr + ")";
    }
    return leftStr + " / " + rightStr;
}


double Pow::evaluate() const {
    double right = expr2->evaluate();
    if (right < 0){
        throw std::invalid_argument("Wykladnik nie moze byc ujemny!");
    }
    return std::pow(expr->evaluate(), right);
}

std::string Pow::to_string() const {
    std::string leftStr = expr->to_string();
    std::string rightStr = expr2->to_string();
    if (dynamic_cast<Add*>(expr) != nullptr || dynamic_cast<Sub*>(expr) != nullptr || dynamic_cast<Mult*>(expr) != nullptr ||
        dynamic_cast<Div*>(expr) != nullptr || dynamic_cast<Pow*>(expr) != nullptr || dynamic_cast<Mod*>(expr) != nullptr){
        leftStr = "(" + leftStr + ")";
    }
    if (dynamic_cast<Add*>(expr2) != nullptr || dynamic_cast<Sub*>(expr2) != nullptr || dynamic_cast<Mult*>(expr2) != nullptr ||
        dynamic_cast<Div*>(expr2) != nullptr || dynamic_cast<Mod*>(expr2) != nullptr){
        rightStr = "(" + rightStr + ")";
    }
    return leftStr + " ^ " + rightStr;
}

double Mod::evaluate() const {
    double right = expr2->evaluate();
    if (right == 0){
        throw std::invalid_argument("Nie mozna dzielic przez 0!");
    }
    return std::fmod(expr->evaluate(), right);
}

std::string Mod::to_string() const {
    std::string leftStr = expr->to_string();
    std::string rightStr = expr2->to_string();
    if (dynamic_cast<Add*>(expr) != nullptr || dynamic_cast<Sub*>(expr) != nullptr || dynamic_cast<Mult*>(expr) != nullptr ||
        dynamic_cast<Div*>(expr) != nullptr || dynamic_cast<Mod*>(expr) != nullptr){
        leftStr = "(" + leftStr + ")";
    }
    if(dynamic_cast<Add*>(expr2) != nullptr || dynamic_cast<Sub*>(expr2) != nullptr || dynamic_cast<Mult*>(expr2) != nullptr ||
        dynamic_cast<Div*>(expr2) != nullptr){
        rightStr = "(" + rightStr + ")";
    }
    return leftStr + " % " + rightStr;
}

double Log::evaluate() const {
    double base = expr->evaluate();
    double value = expr2->evaluate();
    
    if (base <= 0 || base == 1) {
        throw std::invalid_argument("Podstawa logarytmu musi być dodatnia i różna od 1.");
    }
    
    if (value <= 0) {
        throw std::invalid_argument("Argument logarytmu musi być dodatni.");
    }
    
    return std::log(value) / std::log(base);
}


std::string Log::to_string() const {
    return "log(" + expr->to_string() + ", " + expr2->to_string() + ")";
}
