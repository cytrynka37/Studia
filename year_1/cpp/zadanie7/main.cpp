#include <iostream>
#include "colorTN.hpp"
#include "pixel.hpp"
#include "colorPixel.hpp"

int main(){
    Color c1(243, 6, 123);
    std::cout << "Kolor c1: " << c1 << std::endl;

    c1.darken(2);
    std::cout << "Przyciemniony kolor c1: " << c1 << std::endl;

    TransparentColor c2;
    std::cout << "Kolor c2 (konstruktor bezargumentowy): " << c2 << std::endl;

    c2.setBlue(232);
    std::cout << "Kolor c2 po zmianie: " << c2 << std::endl;

    ColorTN c3(255, 8, 37, 232, "czerwony");
    std::cout << "Kolor c3: " << c3 << std::endl;

    Color blended = Color::blend(c1, c3);
    std::cout << "Zmieszane c1 i c3: " << blended << std::endl;

    Pixel p1(200, 500);
    std::cout << "Piksel p1: " << p1 << std::endl;

    std::cout << "Odleglosc od lewego brzegu: " << p1.distanceToLeft() << std::endl;
    std::cout << "Odleglosc od prawego brzegu: " << p1.distanceToRight() << std::endl;
    std::cout << "Odleglosc od gornego brzegu: " << p1.distanceToTop() << std::endl;
    std::cout << "Odleglosc od dolnego brzegu: " << p1.distanceToBottom() << std::endl;

    ColorPixel cp1(180, 200, c1);
    std::cout << "Kolorowy piksel cp1: " << cp1 << std::endl;

    cp1.move(200, 300);
    cp1.setColor(c2);
    std::cout << "cp1 po przemieszczeniu i zmianie koloru: " << cp1 << std::endl;

    std::cout << "Dystans miedzy p1 i cp1 (referencja): " << Pixel::distance(p1, cp1) << std::endl;
    std::cout << "Dystans miedzy p1 i cp1 (wskazniki): " << Pixel::distance(&p1, &cp1) << std::endl;

    try{
        p1.setX(860);
    } catch(std::out_of_range e){
        std::cerr << e.what() << std::endl;
    }

    try{
        Color c3(-1, 4, 5);
        std::cout << c3;
    } catch(std::out_of_range e){
        std::cerr << e.what() << std::endl;
    }

    try{
        c3.setName("Czerwony");
    } catch(std::invalid_argument e){
        std::cerr << e.what() << std::endl;
    }    
}