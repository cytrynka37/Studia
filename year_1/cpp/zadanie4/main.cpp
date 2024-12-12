#include <iostream>
#include "figury.hpp"

int main(){
    Point p(0, 0);
    Vector v(3, 3);

    std::cout << "Punkt p: ";
    p.print();

    std::cout << "Punkt p po przesunięciu o wektor " << v.get_x() << ", " << v.get_y() << ": ";
    p.translate(v);
    p.print();

    Point p1(0, 0);
    std::cout << "Punkt p po obrocie o 90 stopni wokół punktu (0, 0): ";
    p.rotate(90, p1);
    p.print();

    std::cout << "Symetria środkowa p względem punktu (0, 0): ";
    p.centralSymmetry(p1);
    p.print();

    Line l(1, 0, 0);
    std::cout << "Symetria osiowa p względem osi x = 0: ";
    p.axialSymmetry(l);
    p.print();    

    Point p2(-3, -5);
    std::cout << "Odleglosc miedzy punktem p a (-3, -5): " << distance(p, p2) << std::endl << std::endl;

    Segment seg(p, p2);
    std::cout << "Odcinek seg: ";
    seg.print();

    Vector v1(2, 2);
    std::cout << "Odcinek seg po przesunięciu o wektor " << v1.get_x() << ", " << v1.get_y() << ": ";
    seg.translate(v1);
    seg.print();

    std::cout << "Symetria środkowa seg względem punktu (0, 0): ";
    seg.centralSymmetry(p1);
    seg.print();

    std::cout << "Symetria osiowa seg względem osi x = 0: ";
    seg.axialSymmetry(l);
    seg.print();

    std::cout << "Odcinek seg po obrocie o 90 stopni wokół punktu (0, 0): ";
    seg.rotate(90, p1);
    seg.print();

    std::cout << "Czy punkt (-2, -1) nalezy do odcinka seg? " << seg.contains(Point(-2, -1)) << std::endl;

    std::cout << "Czy punkt (-2, -2) nalezy do odcinka seg? " << seg.contains(Point(-2, -2)) << std::endl;

    std::cout << "Dlugosc odcinka seg: " << seg.length() << std::endl;

    Segment s1(Point(-3, -3), Point(-2, -2));
    Segment s2(Point(-4, -4), Point(-1, -1));
    std::cout << "Odcinek s1: ";
    s1.print();
    std::cout << "Odcinek s2: ";
    s2.print();
    std::cout << "Czy odcinki s1 i s2 sa prostopadle? " << perpendicular(s1, s2) << std::endl;
    std::cout << "czy odcinki s1 i s2 sa rownolegle? " <<  parallel(s1, s2) << std::endl << std::endl;;

    std::cout << "Trojkat t: ";
    Triangle t(Point(6, 0), Point(2, 0), Point(6, 4));
    t.print();

    std::cout << "Trojkat t po przesunieciu o wektor (3, 0): ";
    t.translate(Vector(3, 0));
    t.print();

    std::cout << "Pole trojkata t: " << t.area() << std::endl;
    std::cout << "Obwod trojkata t: " << t.perimeter() << std::endl;

    std::cout << "Czy punkt (7, 0) znajduje sie wewnatrz trojkata t? " << t.contains(Point(7, 0)) << std::endl;
    std::cout << "Czy punkt (-1, 4) znajduje sie wewnatrz trojkata t? " << t.contains(Point(-1, 4)) << std::endl;

    std::cout << "Trojkat t2: ";
    Triangle t2(Point(7, 0), Point(8, 0), Point(8, 2));
    t2.print();
    std::cout << "Czy trojkat t2 zawiera sie w t? " << contains_triangle(t, t2) << std::endl;
    std::cout << "Czy trojkaty t2 i t sa rozlaczne? " << disjoint(t, t2) << std::endl;

    std::cout << "Trojkat t po obrocie o 90 stopni wokół punktu (0, 0): ";
    t.rotate(90, p1);
    t.print();

    std::cout << "Symetria środkowa trojkata t względem punktu (0, 0): ";
    t.centralSymmetry(p1);
    t.print();

    std::cout << "Symetria osiowa trojkata t względem osi x = 0: ";
    t.axialSymmetry(l);
    t.print();

    return 0;
}