#include <stdexcept> 
#include <iostream>
#include <math.h>
#pragma once

class Vector{
    private:
        double x, y;
    
    public:
        Vector(double x_val, double y_val);

        double get_x() const { return x; }

        double get_y() const { return y; }
};

class Line{
    private:
        double A, B, C;
    
    public:
        Line(double A, double B, double C);

        double get_A() const { return A; }

        double get_B() const { return B; }

        double get_C() const { return C; }
};

class Point{
    private:
        double x, y;

    public: 
        Point(double x_val, double y_val);

        Point(const Point &other);

        const Point& operator = (const Point &other);

        void translate(const Vector &vector);

        void rotate(double angle_degrees, const Point &point);
        
        void centralSymmetry(const Point &point);

        void axialSymmetry(const Line &line);

        double get_x() const { return x; }

        double get_y() const { return y; }

        void print();
};

class Segment{
    private:
        Point start;
        Point end;
    public:
        Segment(const Point &start_point, const Point &end_point);

        Segment(const Segment &other);

        const Segment& operator = (const Segment &other);

        void translate(const Vector &vector);

        void rotate(double angle, const Point &point);
        
        void centralSymmetry(const Point &point);

        void axialSymmetry(const Line &line);        

        double length();

        bool contains(const Point &point);

        const Point& get_start() const { return start; }

        const Point& get_end() const { return end; }

        void print();
};

class Triangle{
    private:
        Point a;
        Point b;
        Point c;
    public:
        Triangle(const Point &a_point, const Point &b_point, const Point &c_point);

        Triangle(const Triangle &other);

        const Triangle& operator = (const Triangle &other);

        void translate(const Vector &vector);

        void rotate(double angle, const Point &point);
        
        void centralSymmetry(const Point &point);

        void axialSymmetry(const Line &line);

        double perimeter();

        double area() const; 

        bool contains(const Point &point) const;

        const Point& get_a() const { return a; }

        const Point& get_b() const { return b; }

        const Point& get_c() const { return c; }

        void print();
};

double distance(const Point &first, const Point &second);
bool parallel(const Segment &seg1, const Segment &seg2);
bool perpendicular(const Segment &seg1, const Segment &seg2);
bool disjoint(const Triangle &t1, const Triangle &t2);
bool contains_triangle(const Triangle &t1, const Triangle &t2);

