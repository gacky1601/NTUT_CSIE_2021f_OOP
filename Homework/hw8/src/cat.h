#pragma once
#include "pet.h"

class Cat : public Pet {
private:
  static int _amount;

public:
  Cat(string name, double weight) :Pet("CAT", name, weight) {
    if (weight < 2 || weight>6)
      throw range_error("");
    _amount++;
  }
  Cat(const Cat& cat) : Pet(cat) { _amount++; }
  ~Cat() { _amount--; }

  Cat* clone() override { return new Cat(*this); }
  static int amount() { return _amount; }
  void feed() override {
    setWeight(this->weight() + 0.2);
    if (weight() > 6)
      throw out_of_range("");
  }
};
int Cat::_amount = 0;




