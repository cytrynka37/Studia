#pragma once
#include <iostream>

class Color{
    protected:
        unsigned short red;
        unsigned short green;
        unsigned short blue;
    
    public:
        Color();
        Color(unsigned short r, unsigned short g, unsigned short b);
        unsigned short getRed() const;
        unsigned short getGreen() const;
        unsigned short getBlue() const;
        void setRed(unsigned short val);
        void setGreen(unsigned short val);
        void setBlue(unsigned short val);
        void darken(float factor);
        void brighten(float factor);
        static Color blend(Color &c1, Color &c2);
        friend std::ostream& operator<<(std::ostream &out, const Color &color);
};