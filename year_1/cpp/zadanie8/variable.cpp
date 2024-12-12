#include "variable.hpp"
#include <stdexcept>

std::vector<std::pair<std::string, double>> Variable::variables;

Variable::Variable(std::string n) : name(n) {}

double Variable::evaluate() const{
    for (const auto &pair : variables){
        if (pair.first == name){
            return pair.second;
        }
    }
    throw std::invalid_argument("Nie znaleziono zmiennej: " + name);
}

std::string Variable::to_string() const{
    return name;
}

void Variable::addVariable(std::string n, double val){
    for (const auto &pair : variables){
        if (pair.first == n){
            throw std::invalid_argument("Zmienna '" + n + "' już istnieje!");
        }
    }
    variables.push_back(std::make_pair(n, val));
}
void Variable::removeVariable(std::string n){
    for (auto i = variables.begin(); i != variables.end(); i++){
        if (i->first == n){
            variables.erase(i);
            break;
        }
    }
}

void Variable::changeVariable(std::string n, double val){
    for (auto &pair : variables){
        if (pair.first == n){
            pair.second = val;
            break;
        }
    }
}