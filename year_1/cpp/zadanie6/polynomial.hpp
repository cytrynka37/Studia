#pragma once
#include <stdexcept>

class Polynomial{
    private:
        int n;
        double *a;
    
    public:
        Polynomial(int degree = 0, double f = 1.0);
        Polynomial(int degree, const double f[]);
        Polynomial(std::initializer_list<double> f);
        Polynomial(const Polynomial &p);
        Polynomial(Polynomial &&p);
        Polynomial& operator = (const Polynomial &p);
        Polynomial& operator = (Polynomial &&p);
        ~Polynomial ();
        friend std::istream& operator >> (std::istream &we, Polynomial &w);
        friend std::ostream& operator << (std::ostream &wy, const Polynomial &w);
        friend Polynomial operator + (const Polynomial &u, const Polynomial &v);
        friend Polynomial operator - (const Polynomial &u, const Polynomial &v);
        friend Polynomial operator * (const Polynomial &u, double c);
        friend Polynomial operator * (const Polynomial &u, const Polynomial &v);
        Polynomial& operator += (const Polynomial &v);
        Polynomial& operator -= (const Polynomial &v);
        Polynomial& operator *= (const Polynomial &v);
        Polynomial& operator *= (double c);
        double operator () (double x) const; 
        double operator [] (int i) const; 
        double& operator [] (int i); 
};