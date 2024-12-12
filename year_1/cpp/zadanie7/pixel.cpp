#include "pixel.hpp"
#include <iostream>
#include <math.h>

Pixel::Pixel(int x, int y){
    if (x < 0 || x > screen_width || y < 0 || y > screen_height){
        throw std::out_of_range("Piksel jest poza ekranem");
    }
    this->x = x;
    this->y = y;
}

int Pixel::getX() const{
    return x;
}

int Pixel::getY() const{
    return y;
}

void Pixel::setX(int x){
    if (x < 0 || x > screen_width){
        throw std::out_of_range("Piksel jest poza ekranem");
    }
    this->x = x;    
}

void Pixel::setY(int y){
    if (y < 0 || y > screen_height){
        throw std::out_of_range("Piksel jest poza ekranem");
    }
    this->y = y;    
}

int Pixel::distanceToLeft() const{
    return x;
}

int Pixel::distanceToRight() const{
    return screen_width - x;
}

int Pixel::distanceToTop() const{
    return y;
}

int Pixel::distanceToBottom() const{
    return screen_height - y;
}

double Pixel::distance(const Pixel* p1, const Pixel* p2){
    int dx = p1->x - p2->x;
    int dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

double Pixel::distance(const Pixel &p1, const Pixel &p2){
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

std::ostream& operator<<(std::ostream &out, const Pixel &pixel){
    out << "(" << pixel.getX() << ", " << pixel.getY() << ")";
    return out;
}