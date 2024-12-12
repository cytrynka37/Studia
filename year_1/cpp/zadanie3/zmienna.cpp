#include "zmienna.hpp"
#include <stdexcept>

void Liczba :: add(double val) {
    if(count < max_history) count++;
    value = val;
    index = (1 + index) % max_history;
    history[index] = val;
}

void Liczba :: restore() {
    if(count == 1) return;
    index = (index - 1 + max_history) % max_history;
    value = history[index];
}

double Liczba :: peek() {
    return value;
}

Liczba :: Liczba(double val) : value(val), index(0), count(1), history(new double[max_history]) {
    history[0] = val;
}

Liczba :: Liczba() : Liczba(0.0) {}

Liczba :: Liczba(const Liczba &other) : value(other.value), index(0), count(1), history(new double[max_history]) {
    history[0] = other.value;
}

Liczba :: Liczba(Liczba&& other) noexcept: value(other.value), index(other.index), count(other.count), history(other.history) {
    other.count = 0;
    other.index = 0;
    other.value = 0;
    other.history = nullptr;
}

Liczba& Liczba :: operator=(const Liczba &other) {
    if(this != &other) {
        delete[] history;
        history = new double[max_history];
        value = other.value;
        index = 0;
        count = 1;
        history[0] = other.value;
    }
    return *this;
}

Liczba& Liczba :: operator=(Liczba &&other) noexcept {
    if(this != &other) throw std::logic_error("Próba przypisania samej siebie");
    delete[] history;
    value = other.value;
    index = other.index;
    count = other.count;
    history = other.history;

    other.value = 0;
    other.index = 0;
    other.count = 0;
    other.history = nullptr;
    return *this;
}

Liczba :: ~Liczba() {
    delete[] history;
}