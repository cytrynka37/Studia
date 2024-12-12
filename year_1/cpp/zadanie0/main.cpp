#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;

    clog << "Podaj długości trzech boków trójkąta: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        cout << "Błędne dane!\n";
        return 0; 
    }

    // Obwód
    double perimeter = a + b + c;

    // Pole
    double s = perimeter / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "Obwód trójkąta: " << fixed << setprecision(3) << perimeter << endl;
    cout << "Pole powierzchni trójkąta: " << fixed << setprecision(3) << area << endl;

    return 0;
}
