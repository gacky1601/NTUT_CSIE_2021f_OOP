#pragma once

class Dog : public Pet {
public:
    Dog(string name, double weight) {
        if (weight > 50 || weight < 10)
            throw range_error("");
        _name = name;
        _weight = weight;
    }
    void feed() override {
        _weight += 0.8;
        if (_weight > 50)
            throw out_of_range("");
    }

};