#pragma once
#include "pixel.hpp"
#include "color.hpp" 

class ColorPixel : public Pixel{
    private:
        Color color;
    
    public:
        ColorPixel(int dx, int dy, const Color &c);
        Color getColor() const;
        void setColor(const Color &c);
        void move(int dx, int dy);
        friend std::ostream& operator<<(std::ostream &out, const ColorPixel &pixel);
};