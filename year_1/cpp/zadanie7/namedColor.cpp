#include "namedColor.hpp"

NamedColor::NamedColor() : Color(), name("") {}

NamedColor::NamedColor(unsigned short r, unsigned short g, unsigned short b, std::string n) : Color(r, g, b) {
    for (char c : n){
        if(!islower(c)){
            throw std::invalid_argument("Nazwa koloru może składać się tylko z małych liter alfabetu angielskiego");
        }
    }
    name = n;
}

std::string NamedColor::getName() const{
    return name;
}

void NamedColor::setName(std::string n){
    for (char c : n){
        if(!islower(c)){
            throw std::invalid_argument("Nazwa koloru może składać się tylko z małych liter alfabetu angielskiego");
        }
    }
    name = n;    
}

std::ostream &operator<<(std::ostream &out, const NamedColor &color){
    out << "(" << color.getRed() << ", " << color.getGreen() << ", " << color.getBlue() << "), nazwa: " << color.getName();
    return out;
}
