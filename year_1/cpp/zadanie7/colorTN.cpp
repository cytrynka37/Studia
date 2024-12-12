#include "colorTN.hpp"

ColorTN::ColorTN() : Color() {
  this->alpha = 0;
  this->name = "";
}

ColorTN::ColorTN(unsigned short r, unsigned short g, unsigned short b, unsigned short a, std::string n) : Color(r, g, b) {
    this->alpha = a;
    this->name = n;
}


std::ostream& operator<<(std::ostream &out, const ColorTN &color){
    out << "(" << color.getRed() << ", " << color.getGreen() << ", " << color.getBlue() << "), " << "nazwa: " << color.getName() << ", przezroczystosc: " << color.getAlpha();
    return out;
}