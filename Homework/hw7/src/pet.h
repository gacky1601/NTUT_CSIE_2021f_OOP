#pragma once
#include <string>
using namespace std;

class Pet {
protected:
    string _name;
    double _weight;
public:

    Pet() {}
    Pet(string name, double weight) {
        _name = name;
        _weight = weight;
    }
    virtual ~Pet() {}
    virtual void feed() = 0;
    double weight() { return _weight; }
    string name() { return _name; }
};
