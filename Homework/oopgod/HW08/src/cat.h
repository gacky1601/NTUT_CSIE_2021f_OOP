#pragma once

#include "pet.h"

class Cat : public Pet
{
private:
    static int _amount;

public:
    Cat(std::string name, double weight) : Pet("CAT", name, weight)
    {
        if (weight < 2 || weight > 6)
            throw std::range_error("Error");
        _amount++;
    }

    Cat(Cat const &other) : Pet(other)
    {
        _amount++;
    }

    ~Cat() override
    {
        _amount--;
    }

    Cat *clone() const override
    {
        return new Cat(*this);
    }

    void feed() override
    {
        setWeight(weight() + 0.2);
        if (weight() > 6)
            throw std::out_of_range("Error");
    }

    static int amount()
    {
        return _amount;
    }
};

int Cat::_amount = 0;