#pragma once

class Cat : public Pet {
public:
    Cat(string name, double weight) {
        if (weight > 6 || weight < 2)
            throw range_error("");
        _name = name;
        _weight = weight;
    }
    void feed() override {
        _weight += 0.2;
        if (_weight > 6)
            throw out_of_range("");
    }
};