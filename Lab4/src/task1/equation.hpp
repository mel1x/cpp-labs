#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class QuadraticEquation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation();
    QuadraticEquation(double a);
    QuadraticEquation(double a, double b);
    QuadraticEquation(double a, double b, double c);
    QuadraticEquation(QuadraticEquation &Equation);

    double getA() const;
    double getB() const;
    double getC() const;

    void setA(double a);
    void setB(double b);
    void setC(double c);

    double getDiscriminant() const;

    vector<double> solve() const;

    wstring toString() const;

    friend wostream& operator<<(wostream& out, const QuadraticEquation& eq);
    
    QuadraticEquation& operator++();
    QuadraticEquation operator++(int);
    

    QuadraticEquation& operator--();
    QuadraticEquation operator--(int);


    operator double() const;
    explicit operator bool() const;

    
    bool operator==(const QuadraticEquation& other) const;
    bool operator!=(const QuadraticEquation& other) const;
};