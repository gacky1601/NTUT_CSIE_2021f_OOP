#pragma once
#include <string>
#include <stdexcept>

class Pet
{
protected:
    std::string _name;
    double _weight;

public:
    Pet() {}

    Pet(std::string name, double weight)
    {
        _name = name;
        _weight = weight;
    }

    ~Pet() {}

    std::string name() const
    {
        return _name;
    }

    double weight() const
    {
        return _weight;
    }

    virtual void feed() = 0;
};