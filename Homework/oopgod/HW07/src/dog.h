#pragma once

#include "pet.h"

class Dog : public Pet
{
public:
    Dog() {}

    Dog(std::string name, double weight) : Pet(name, weight)
    {
        if (weight < 10 || weight > 50)
            throw std::range_error("Error");
    }

    void feed() override
    {
        _weight += 0.8;
        if (_weight > 50)
            throw std::out_of_range("Error");
    }
};