#pragma once

#include <string>
#include <stdexcept>

class Pet
{
private:
    double _weight;
    std::string _kind;
    std::string _name;
    static int _amount;

protected:
    void setWeight(double weight)
    {
        _weight = weight;
    }

public:
    Pet(std::string const &kind, std::string const &name, double const weight) : _kind(kind), _name(name), _weight(weight)
    {
        _amount++;
    }

    Pet(Pet const &other) : _kind(other._kind), _name(other._name), _weight(other._weight)
    {
        _amount++;
    }

    virtual ~Pet()
    {
        _amount--;
    }

    virtual Pet *clone() const = 0;

    virtual void feed() = 0;

    std::string kind() const
    {
        return _kind;
    }

    std::string name() const
    {
        return _name;
    }

    double weight() const
    {
        return _weight;
    }

    static int amount()
    {
        return _amount;
    }
};

int Pet::_amount = 0;