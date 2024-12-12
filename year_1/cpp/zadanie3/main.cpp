#include <iostream>
#include "zmienna.hpp"

int main() {
    Liczba x(4);
    std::cout << "Wartosc zmiennej x: " << x.peek() << std::endl;
    x.add(5);
    x.add(6);
    x.add(2);
    std::cout << "Wartosc zmiennej x (4, (5, 6, 2)): " << x.peek() << std::endl;
    x.restore();
    std::cout << "Wartosc zmiennej x po uzyciu restore: " << x.peek() << std::endl;

    Liczba a(x);
    std::cout << "Wartosc a (kopia x): " << a.peek() << std::endl;
    a.restore();
    std::cout << "Wartosc a po uzyciu restore: " << a.peek() << std::endl;

    Liczba y = std::move(x);
    std::cout << "Wartosc y (przeniesienie x): " << y.peek() << std::endl;
    y.restore();
    y.restore();
    std::cout << "Wartosc y po uzyciu restore 2 razy: " << y.peek() << std::endl;

    return 0;
}