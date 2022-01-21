#pragma once

#include "pet.h"

class Dog : public Pet
{
private:
    static int _amount;

public:
    Dog(std::string name, double weight) : Pet("DOG", name, weight)
    {
        if (weight < 10 || weight > 50)
            throw std::range_error("Error");
        _amount++;
    }

    Dog(Dog const &other) : Pet(other)
    {
        _amount++;
    }

    ~Dog() override
    {
        _amount--;
    }

    Dog *clone() const override
    {
        return new Dog(*this);
    }

    void feed() override
    {
        setWeight(weight() + 0.8);
        if (weight() > 50)
            throw std::out_of_range("Error");
    }

    static int amount()
    {
        return _amount;
    }
};

int Dog::_amount = 0;