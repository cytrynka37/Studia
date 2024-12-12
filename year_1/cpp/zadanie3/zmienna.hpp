#pragma once
#include <stdexcept>

class Liczba
{
    private:
        double value;
        int max_history = 3;
        double *history;
        int index;
        int count;

    public:
        Liczba(double val);

        Liczba();

        Liczba(const Liczba &other);

        Liczba(Liczba&& other) noexcept;

        Liczba& operator=(const Liczba &other);

        Liczba& operator=(Liczba &&other) noexcept;

        ~Liczba();

        void add(double val);

        void restore();
        
        double peek();
};