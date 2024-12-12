#pragma once
#include "color.hpp"
#include <stdexcept>

class NamedColor : public virtual Color{
    protected:
        std::string name;
    
    public:
        NamedColor();
        NamedColor(unsigned short r, unsigned short g, unsigned short b, std::string n);
        std::string getName() const;
        void setName(std::string n);
        friend std::ostream& operator<<(std::ostream &out, const NamedColor &color);
};