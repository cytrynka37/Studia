#pragma once
#include "transparentColor.hpp"
#include "namedColor.hpp" 
#include <stdexcept>

class ColorTN : public TransparentColor, public NamedColor{
    public:
        ColorTN();

        ColorTN(unsigned short r, unsigned short g, unsigned short b, unsigned short a, std::string n);

        friend std::ostream& operator<<(std::ostream &out, const ColorTN &color);
};