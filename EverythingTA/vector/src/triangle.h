#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "math_vector.h"
#include "shape.h"
#include <iostream>

class Triangle : public Shape { // private, protected
public:
    // Constructors are also member functions
    Triangle(){
        log += "=>Triangle ";
    }
    Triangle(const MathVector &u, const MathVector &w, const MathVector &v)
    {
        log += "=>Triangle ";
        _u = u;
        _w = w;
        _v = v;
    }
    // initializer list
    Triangle(const MathVector &u, const MathVector &w, const MathVector &v, std::string name) :Shape(name) {
        log += "=>Triangle ";
        _u = u;
        _w = w;
        _v = v;
        // _name = name;
    }
    ~Triangle() override {
        log += "=>~Triangle ";
    }

    double perimeter() const override
    {
        double a, b, c;
        a = (_u - _w).length();
        b = (_w - _v).length();
        c = (_v - _u).length();
        return a + b + c;
    }

    double area() const override
    {
        double a, b, c, s;
        a = (_u - _w).length();
        b = (_w - _v).length();
        c = (_v - _u).length();
        s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    std::string getName() const override{
        return "Triangle:: " + _name;
    }

    std::string toString() const override{
        std::stringstream ss;
        ss << _name;
        ss << "\n";
        ss << _u.toString() << "\n" << _w.toString() << "\n" << _v.toString();
        return ss.str();
    }

    friend std::ostream &operator<<( std::ostream &output, const Triangle &T ) { 
        output << T._name << "\n" << T._u.toString() << "\n" << T._w.toString() << "\n" << T._v.toString();
        return output;            
    }

    friend std::istream &operator>>( std::istream  &input, Triangle &T ) { 
        input >> T._u >> T._w >> T._v;
        return input;            
    }
private:
    MathVector _u, _w, _v;
};

#endif