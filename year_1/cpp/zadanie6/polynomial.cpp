#include "polynomial.hpp"
#include <iostream>

Polynomial::Polynomial(int degree, double f) : n(degree), a(new double[n + 1]){
    if (n < 0) throw std::out_of_range("Stopien wielomianu nie moze byc mniejszy od 0");
    for (int i = 0; i <= degree; i++){
        a[i] = f;
    }
}

Polynomial::Polynomial(int degree, const double f[]) : n(degree), a(new double[n + 1]){
    if (n < 0) throw std::out_of_range("Stopien wielomianu nie moze byc mniejszy od 0");
    if (f[n] == 0 && n != 0) throw std::invalid_argument("Wspolczynnik przy najwyzszej potedze nie moze byc zerem");
    for (int i = 0; i <= n; i++){
        a[i] = f[i];
    }
}

Polynomial::Polynomial(std::initializer_list<double> f) : n(f.size() - 1), a(new double[n + 1]){
    int i = 0;
    for (double elem : f){
        a[i++] = elem;
    }               
    if (a[n] == 0 && n != 0) throw std::invalid_argument("Wspolczynnik przy najwyzszej potedze nie moze byc zerem");
}

Polynomial::Polynomial(const Polynomial &p) : n(p.n), a(new double[n + 1]){
    for (int i = 0; i <= n; i++){
        a[i] = p.a[i];
    }
}

Polynomial::Polynomial(Polynomial &&p) : n(p.n), a(p.a){
    p.a = nullptr;
    p.n = 0;
}

Polynomial& Polynomial::operator=(const Polynomial &p){
    if (this != &p){
        delete[] a;
        n = p.n;
        a = new double[n + 1];
        for (int i = 0; i <= n; i++){
            a[i] = p.a[i];
        }        
    }
    return *this;
}

Polynomial& Polynomial::operator=(Polynomial &&p){
    if (this != &p){
        delete[] a;
        n = p.n;
        a = p.a;
        p.a = nullptr;
        p.n = 0;    
    }
    return *this;    
}

Polynomial::~Polynomial(){
    delete[] a;
}

std::istream& operator>>(std::istream &we, Polynomial &w){
    int dgr;
    double a;
    double *f = new double[dgr + 1];

    we >> dgr;
    for (int i = 0; i <= dgr; i++) {
        we >> a;
        f[i] = a;
    }

    w = Polynomial(dgr, f);
    delete[] f;
    return we;
}

std::ostream& operator<<(std::ostream &wy, const Polynomial &w){
    for (int i = w.n; i >= 0; --i){
        if (w.a[i] == 0){
            continue;
        } else if (i > 1){
            if (w.a[i] == 1){
                wy << "x^" << i;
            } else if (w.a[i] == -1){
                wy << "-x^" << i;
            } else wy << w.a[i] << "x^" << i;
            wy << " + ";
        } else if (i == 1){
            if (w.a[i] == 1){
                wy << "x";
            } else if (w.a[i] == -1){
                wy << "-x";
            } else wy << w.a[i] << "x";
            wy << " + ";
        } else wy << w.a[i];
    }
    return wy;
}

Polynomial& Polynomial::operator+=(const Polynomial &v){
    int max_degree = std::max(n, v.n);
    double *newA = new double[max_degree + 1]{0};

    for (int i = 0; i <= max_degree; i++){
        newA[i] = (i <= n ? a[i] : 0) + (i <= v.n ? v.a[i] : 0);
    }

    while (newA[max_degree] == 0 && max_degree > 0){
        max_degree--;
    }

    delete[] a;
    a = new double[max_degree + 1];
    for (int i = 0; i <= max_degree; i++){
        a[i] = newA[i];
    }

    delete[] newA;
    n = max_degree;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial &v){
    int max_degree = std::max(n, v.n);
    double *newA = new double[max_degree + 1]{0};

    for (int i = 0; i <= max_degree; i++) {
        newA[i] = (i <= n ? a[i] : 0) - (i <= v.n ? v.a[i] : 0);
    }

    while (newA[max_degree] == 0 && max_degree > 0){
        max_degree--;
    }

    delete[] a;
    a = new double[max_degree + 1];
    for (int i = 0; i <= max_degree; i++){
        a[i] = newA[i];
    }

    delete[] newA;
    n = max_degree;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial &v){
    int max_degree = n + v.n;
    double *newA = new double[max_degree + 1]{0};
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= v.n; j++){
            newA[i + j] += a[i] * v.a[j];
        }
    }

    while(newA[max_degree] == 0 && max_degree > 0){
        max_degree--;
    }

    delete[] a;
    a = new double[max_degree + 1];
    for (int i = 0; i <= max_degree; i++){
        a[i] = newA[i];
    }

    delete[] newA;
    n = max_degree;
    return *this;
}

Polynomial& Polynomial::operator*=(double c){
    if (c == 0){
        delete[] a;
        n = 0;
        a = new double[1]{0};
        return *this;
    }
    for (int i = 0; i <= n; i++){
        a[i] *= c;
    }
    return *this;
}

Polynomial operator+(const Polynomial &u, const Polynomial &v){
    Polynomial res(u);
    res += v;
    return res;
}

Polynomial operator-(const Polynomial &u, const Polynomial &v){
    Polynomial res(u);
    res -= v;
    return res;
}

Polynomial operator*(const Polynomial &u, double c){
    Polynomial res(u);
    res *= c;
    return res;
}

Polynomial operator*(const Polynomial &u, const Polynomial &v){
    Polynomial res(u);
    res *= v;
    return res;
}

double Polynomial::operator()(double x) const{
    double value = a[n];
    for(int i = n - 1; i >= 0; i--){
        value = (value * x) + a[i];
    }
    return value;
}

double Polynomial::operator [] (int i) const{
    if (i < 0 || i > n){
        throw std::invalid_argument("Indeks poza zasiegiem");
    }
    return a[i];    
}
        
double& Polynomial::operator [] (int i){
    if (i == n && i != 0 && a[i] == 0){
        throw std::invalid_argument("Wspolczynnik przy najwyzszej potedze nie moze byc zerem");
    }

    if (i < 0 || i > n){
        throw std::invalid_argument("Indeks poza zasiegiem");
    }
    return a[i];     
}