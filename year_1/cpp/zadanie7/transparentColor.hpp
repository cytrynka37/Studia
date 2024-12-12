#pragma once
#include "color.hpp"

class TransparentColor : public virtual Color{
    protected:
        unsigned short alpha;
    
    public:
        TransparentColor();
        TransparentColor(unsigned short r, unsigned short g, unsigned short b, unsigned short a);
        unsigned short getAlpha() const;
        void setAlpha(unsigned short val);
        friend std::ostream& operator<<(std::ostream &out, const TransparentColor &color);
};