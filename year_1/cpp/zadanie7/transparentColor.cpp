#include "transparentColor.hpp"
#include <stdexcept>

TransparentColor::TransparentColor() : Color(), alpha(255) {}

TransparentColor::TransparentColor(unsigned short r, unsigned short g, unsigned short b, unsigned short a) : Color(r, g, b) {
    if (a > 255){
        throw std::out_of_range("Wartosc wspolczynnika alpha poza zakresem 0-255");
    }
    alpha = a;
}

unsigned short TransparentColor::getAlpha() const{
    return alpha;
}

void TransparentColor::setAlpha(unsigned short val){
    if (val > 255){
        throw std::out_of_range("Wartosc wspolczynnika alpha poza zakresem 0-255");
    }
    alpha = val;
}

std::ostream &operator<<(std::ostream &out, const TransparentColor &color){
    out << "(" << color.getRed() << ", " << color.getGreen() << ", " << color.getBlue() << "), przezroczystosc: " << color.getAlpha();
    return out;
}
