#include "figury.hpp"

double distance(const Point &first, const Point &second){
    double xd = first.get_x() - second.get_x();
    double yd = first.get_y() - second.get_y();
    return sqrt(xd * xd + yd * yd);
}

bool parallel(const Segment &seg1, const Segment &seg2){
    double dx1 = seg1.get_start().get_x() - seg1.get_end().get_x();
    double dx2 = seg2.get_start().get_x() - seg2.get_end().get_x();
    if(dx1 == 0 || dx2 == 0){
        throw std::invalid_argument("Dzielenie przez 0!");
    }

    double a1 = (seg1.get_start().get_y() - seg1.get_end().get_y()) / dx1; 
    double a2 = (seg2.get_start().get_y() - seg2.get_end().get_y()) / dx2; 
    return a1 == a2;
}

bool perpendicular(const Segment &seg1, const Segment &seg2){
    double dx1 = seg1.get_start().get_x() - seg1.get_end().get_x();
    double dx2 = seg2.get_start().get_x() - seg2.get_end().get_x();
    if(dx1 == 0 || dx2 == 0){
        throw std::invalid_argument("Dzielenie przez 0!");
    }

    double a1 = (seg1.get_start().get_y() - seg1.get_end().get_y()) / dx1; 
    double a2 = (seg2.get_start().get_y() - seg2.get_end().get_y()) / dx2; 
    return a1 == -1 * a2;
}

bool disjoint(const Triangle &t1, const Triangle &t2){
    return !(t1.contains(t2.get_a()) || t1.contains(t2.get_b()) || t1.contains(t2.get_c()) ||
        t2.contains(t1.get_a()) || t2.contains(t1.get_b()) || t2.contains(t1.get_c()));
}

bool contains_triangle(const Triangle &t1, const Triangle &t2){
    return t1.contains(t2.get_a()) && t1.contains(t2.get_b()) && t1.contains(t2.get_c());
}

double round6(double num) {
    return std::round(num * 10000000.0) / 10000000.0;
}

Vector :: Vector(double x_val, double y_val) : x(x_val), y(y_val) {}

Line :: Line(double A_val, double B_val, double C_val) : A(A_val), B(B_val), C(C_val) {
    if (A == 0 && B == 0) {
    throw std::invalid_argument("A i B nie mogą wynosić jednocześnie 0.");
    }
}

Point :: Point(double x_val, double y_val) : x(x_val), y(y_val) {}

Point :: Point(const Point &other) : x(other.x), y(other.y) {}

const Point& Point :: operator = (const Point &other){
    x = other.x;
    y = other.y;
    return *this;
}

void Point :: translate(const Vector &vector){
    x = round6(x + vector.get_x());
    y = round6(y + vector.get_y());
}

void Point :: rotate(double angle_degrees, const Point &point){
    double angle = angle_degrees * M_PI / 180.0;
    double x0 = x - point.get_x();
    double y0 = y - point.get_y();
    double new_x = x0 * cos(angle) - y0 * sin(angle);
    double new_y = x0 * sin(angle) + y0 * cos(angle);
    x = round6(new_x + point.get_x());
    y = round6(new_y + point.get_y());

}
    
void Point :: centralSymmetry(const Point &point){
    x = round6(2 * point.get_x() - x);
    y = round6(2 * point.get_y() - y);
}

void Point :: axialSymmetry(const Line &line){
    double A = line.get_A();
    double B = line.get_B();
    double C = line.get_C();
    
    double dist = std::fabs(A * x + B * y + C) / sqrt(A * A + B * B);

    x = round6(x - 2 * A * dist / (A * A + B * B));
    y = round6(y - 2 * B * dist / (A * A + B * B));

}

void Point :: print(){
    std::cout << "[" << x << ", " << y << "]" << std::endl;
}

Segment :: Segment(const Point &start_point, const Point &end_point) : start(start_point), end(end_point) {
    if(start.get_x() == end.get_x() && start.get_y() == end.get_y()){
        throw std::invalid_argument("Oba konce odcinka maja te same wspolrzedne!");
    }
}

Segment :: Segment(const Segment &other) : start(other.start), end(other.end) {}

const Segment& Segment :: operator = (const Segment &other){
    start = other.start;
    end = other.end;
    return *this;
}

void Segment :: translate(const Vector &vector){
    start.translate(vector);
    end.translate(vector);
}

void Segment :: rotate(double angle, const Point &point){
    start.rotate(angle, point);
    end.rotate(angle, point);
}

void Segment :: centralSymmetry(const Point &point){
    start.centralSymmetry(point);
    end.centralSymmetry(point);
}

void Segment :: axialSymmetry(const Line &line){
    start.axialSymmetry(line);
    end.axialSymmetry(line);
}

double Segment :: length(){
    return distance(start, end);
}

bool Segment :: contains(const Point &point) {
    double min_x = std::min(start.get_x(), end.get_x());
    double max_x = std::max(start.get_x(), end.get_x());
    double min_y = std::min(start.get_y(), end.get_y());
    double max_y = std::max(start.get_y(), end.get_y());

    if (point.get_x() >= min_x && point.get_x() <= max_x &&
        point.get_y() >= min_y && point.get_y() <= max_y) {
        return true;
    } else {
        return false;
    }
}

void Segment :: print(){
    std::cout << "[" << start.get_x() << ", " << start.get_y() << "], [" << end.get_x() << ", " << end.get_y() << "]" << std::endl;
}

Triangle :: Triangle(const Point &a_point, const Point &b_point, const Point &c_point) : a(a_point), b(b_point), c(c_point) {
    double ab_length = distance(a, b);
    double bc_length = distance(b, c);
    double ac_length = distance(a, c);
    
    if (ab_length + bc_length <= ac_length || ab_length + ac_length <= bc_length || ac_length + bc_length <= ab_length) {
        throw std::invalid_argument("Nieprawidlowe wspolrzedne trojkata!");
    }
}

Triangle :: Triangle(const Triangle &other) : a(other.a), b(other.b), c(other.c) {}

const Triangle& Triangle :: operator = (const Triangle &other){
    a = other.a;
    b = other.b;
    c = other.c;
    return *this;    
}

void Triangle :: translate(const Vector &vector){
    a.translate(vector);
    b.translate(vector);
    c.translate(vector);
}

void Triangle :: rotate(double angle, const Point &point){
    a.rotate(angle, point);
    b.rotate(angle, point);
    c.rotate(angle, point);
}

void Triangle :: centralSymmetry(const Point &point){
    a.centralSymmetry(point);
    b.centralSymmetry(point);
    c.centralSymmetry(point);
}

void Triangle :: axialSymmetry(const Line &line){
    a.axialSymmetry(line);
    b.axialSymmetry(line);
    c.axialSymmetry(line); 
}      

double Triangle :: perimeter(){
    return distance(a, b) + distance(b, c) + distance(c, a);
}

double Triangle :: area() const{
    return 0.5 * std::fabs((b.get_x() - a.get_x()) * (c.get_y() - a.get_y()) - (b.get_y() - a.get_y()) * (c.get_x() - a.get_x()));
}

bool Triangle::contains(const Point &point) const {
    double denom = ((b.get_y() - c.get_y())*(a.get_x() - c.get_x()) + (c.get_x() - b.get_x())*(a.get_y() - c.get_y()));
    double alpha = ((b.get_y() - c.get_y())*(point.get_x() - c.get_x()) + (c.get_x() - b.get_x())*(point.get_y() - c.get_y())) / denom;
    double beta = ((c.get_y() - a.get_y())*(point.get_x() - c.get_x()) + (a.get_x() - c.get_x())*(point.get_y() - c.get_y())) / denom;
    double gamma = 1.0 - alpha - beta;

    return alpha >= 0 && beta >= 0 && gamma >= 0;
}


void Triangle :: print(){
    std::cout << "[" << a.get_x() << ", " << a.get_y() << "], [" << b.get_x() << ", " << b.get_y() << "], [" << c.get_x() << ", " << c.get_y() << "]" << std::endl;
}