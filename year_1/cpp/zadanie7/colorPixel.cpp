#include "colorPixel.hpp"
#include <iostream>

ColorPixel::ColorPixel(int dx, int dy, const Color &c) : Pixel(dx, dy), color(c) {}

Color ColorPixel::getColor() const{
    return color;
}

void ColorPixel::setColor(const Color &c){
    color = c;
}

void ColorPixel::move(int dx, int dy){
    int new_x = getX() + dx;
    int new_y = getY() + dy;
    
    if (new_y < 0 || new_y > screen_height || new_x < 0 || new_x > screen_width){
        throw std::out_of_range("Piksel jest poza ekranem");
    }

    setX(new_x);
    setY(new_y);
}

std::ostream& operator<<(std::ostream &out, const ColorPixel &pixel){
    out << "(" << pixel.getX() << ", " << pixel.getY() << "), (" << pixel.getColor().getRed() << ", " << pixel.getColor().getGreen() << ", " << pixel.getColor().getBlue() << ")";
    return out;
}