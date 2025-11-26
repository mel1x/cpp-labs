#include "equation.hpp"
#include <cmath>
#include <cstdlib>
#include <sstream>


QuadraticEquation::QuadraticEquation()
    : a(1.0), b(0.0), c(0.0) {
}
QuadraticEquation::QuadraticEquation(double a)
    : a(a), b(0.0), c(0.0) {
}
QuadraticEquation::QuadraticEquation(double a, double b) 
    : a(a), b(b), c(0.0) {
}
QuadraticEquation::QuadraticEquation(double a, double b, double c) 
    : a(a), b(b), c(c) {
}

double QuadraticEquation::getA() const {
    return a;
}
double QuadraticEquation::getB() const {
    return b;
}
double QuadraticEquation::getC() const {
    return c;
}

void QuadraticEquation::setA(double newA) {
    a = newA;
}
void QuadraticEquation::setB(double newB) {
    b = newB;
}
void QuadraticEquation::setC(double newC) {
    c = newC;
}

double QuadraticEquation::getDiscriminant() const {
    return b * b - 4 * a * c;
}

vector<double> QuadraticEquation::solve() const {
    vector<double> roots;
    
    if (a == 0) {
        if (b != 0) {
            roots.push_back(-c / b);
        }
        return roots;
    }
    
    double D = getDiscriminant();
    
    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        roots.push_back(x1);
        roots.push_back(x2);
    }
    else if (D == 0) {
        double x = -b / (2 * a);
        roots.push_back(x);
    }
    
    return roots;
}

wstring QuadraticEquation::toString() const {
    wstringstream ss;
    ss << a << L"x^2 " << (b < 0? L"- " : L"+ ") << abs(b) << L"x " << (c < 0? L"- " : L"+ ") << abs(c) << L" = 0";
    return ss.str();
}

wostream& operator<<(wostream& out, const QuadraticEquation& eq) {
    out << eq.a << L"x^2 " << (eq.b < 0? L"- " : L"+ ") << abs(eq.b) << L"x " << (eq.c < 0? L"- " : L"+ ") << abs(eq.c) << L" = 0";
    return out;
}

QuadraticEquation& QuadraticEquation::operator++() {
    a += 1;
    b += 1;
    c += 1;
    return *this;
}
QuadraticEquation QuadraticEquation::operator++(int) {
    QuadraticEquation old = *this;
    a += 1;
    b += 1;
    c += 1;
    return old;
}

QuadraticEquation& QuadraticEquation::operator--() {
    a -= 1;
    b -= 1;
    c -= 1;
    return *this;
}
QuadraticEquation QuadraticEquation::operator--(int) {
    QuadraticEquation old = *this;
    a -= 1;
    b -= 1;
    c -= 1;
    return old;
}

QuadraticEquation::operator double() const {
    return getDiscriminant();
}
QuadraticEquation::operator bool() const {
    return getDiscriminant() >= 0;
}

bool QuadraticEquation::operator==(const QuadraticEquation& other) const {
    return (a == other.a) && (b == other.b) && (c == other.c);
}
bool QuadraticEquation::operator!=(const QuadraticEquation& other) const {
    return !(*this == other);
}