#pragma once
#include <iostream>

class Pixel{
    protected:
        static const int screen_width = 800;
        static const int screen_height = 600;
        int x;
        int y;

    public:
        Pixel(int x, int y);
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        int distanceToLeft() const;
        int distanceToRight() const;
        int distanceToTop() const;
        int distanceToBottom() const;
        static double distance(const Pixel *p1, const Pixel *p2);
        static double distance(const Pixel &p1, const Pixel &p2);
        friend std::ostream& operator<<(std::ostream &out, const Pixel &pixel);
};