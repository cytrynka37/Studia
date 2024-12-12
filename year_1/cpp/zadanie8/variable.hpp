#pragma once
#include "expression.hpp"
#include <vector>

class Variable : public Expression{
    private:
    static std::vector<std::pair<std::string, double>> variables;
    std::string name;

    public:
    Variable(std::string n);
    double evaluate() const override;
    std::string to_string() const override;
    static void addVariable(std::string n, double val);
    static void removeVariable(std::string n);
    static void changeVariable(std::string n, double val);
};