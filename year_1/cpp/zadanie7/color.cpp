#include "color.hpp"
#include <iostream>

Color::Color() : red(0), green(0), blue(0) {}

Color::Color(unsigned short r, unsigned short g, unsigned short b){
    if (r > 255 ||g > 255 || b > 255){
        throw std::out_of_range("Wartosc koloru poza zakresem 0-255");
    }
    red = r;
    green = g;
    blue = b;
}

unsigned short Color::getRed() const{
    return red;
}

unsigned short Color::getGreen() const{
    return green;
}

unsigned short Color::getBlue() const{
    return blue;
}

void Color::setRed(unsigned short val){
    if (val > 255){
        throw std::out_of_range("Wartosc koloru poza zakresem 0-255");
    }
    red = val;
}

void Color::setGreen(unsigned short val){
    if (val > 255){
        throw std::out_of_range("Wartosc koloru poza zakresem 0-255");
    }
    green = val;
}

void Color::setBlue(unsigned short val){
    if (val > 255){
        throw std::out_of_range("Wartosc koloru poza zakresem 0-255");
    }
    blue = val;
}

void Color::darken(float factor){
    red = red / factor;
    green = green / factor;
    blue = blue / factor;
}

void Color::brighten(float factor){
    red = (red * factor > 255) ? 255 : (red * factor);
    green = (green * factor > 255) ? 255 : (green * factor);
    blue = (blue * factor > 255) ? 255 : (blue * factor);
}

Color Color::blend(Color &c1, Color &c2) {
    unsigned short r = (c1.red + c2.red) / 2;
    unsigned short g = (c1.green + c2.green) / 2;
    unsigned short b = (c1.blue + c2.blue) / 2;
    return Color(r, g, b);
}

std::ostream& operator<<(std::ostream &out, const Color &color){
    out << "(" << color.getRed() << ", " << color.getGreen() << ", " << color.getBlue() << ")";
    return out;
}
