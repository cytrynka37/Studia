#include "polynomial.hpp"
#include <iostream>

int main(){
    Polynomial x;
    std::cout << "wprwadz wielomian x (n a0, a1 ... a(n)): ";
    std::cin >> x;
    std::cout << "wielomian x: " << x << std::endl;

    Polynomial a;
    std::cout << "a (konstruktor bezargumentowy) = " << a << std::endl;

    Polynomial w(3);
    std::cout << "w (stopien 3 i domyslne wspolczynniki) = " << w << std::endl;

    Polynomial w1({2.0, 2.0, 4.0});
    std::cout << "w1 (lista inicjalizacyjna) = " << w1 << std::endl;

    double coefficients[] = {3.0, 3.0, 4.0};
    Polynomial w2(2, coefficients);
    std::cout << "w2 (wlasne wspolczynniki) = " << w2 << std::endl;

    std::cout << "w1 + w2 = " << w1 + w2 << std::endl;
    std::cout << "w1 - x = " << w1 - x << std::endl;
    std::cout << "w1 * w2 = " << w1 * w2 << std::endl;
    std::cout << "x * 3 = " << x * 3 << std::endl;

    x += w1;
    std::cout << "x += w1 = " << x << std::endl;
    w2 -= w1;
    std::cout << "w2 -= w1 = " << w2 << std::endl;
    w1 *= x;
    std::cout << "w1 *= x = " << w1 << std::endl;
    w2 *= 2;
    std::cout << "w2 *= 2 = " << w2 << std::endl; 

    std::cout << "wartosc w2 dla x = 2: " << w2(2) << std::endl;

    Polynomial w4(w2);
    std::cout << "Wielomian w4 - kopia w2: " << w4 << std::endl;

    Polynomial w5 = std::move(w2);
    std::cout << "Wielomian w5 - przeniesiony z w2: " << w5 << std::endl;

    std::cout << "Wspolczynnik przy x^1 w w5: " << w5[1] << std::endl;

    w5[1] = 3;
    std::cout << "Zmieniony wspolczynnik przy x^1 w w5: " << w5[1] << std::endl;

    try{
        double c = w5[2];
    } catch(std::invalid_argument e){
        std::cerr << e.what() << std::endl;
    }

    try{
        double coefficients[] = {3.0, 3.0, 0.0};
        Polynomial w6(2, coefficients);
    } catch(std::invalid_argument e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
