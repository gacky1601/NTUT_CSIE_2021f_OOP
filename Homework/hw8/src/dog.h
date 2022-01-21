#pragma once
#include "pet.h"

class Dog : public Pet {
private:
  static int _amount;
public:
  Dog(string name, double weight) :Pet("DOG", name, weight) {
    if (weight < 10 || weight>50)
      throw range_error("");
    _amount++;
  }
  Dog(const Dog& dog) : Pet(dog) { _amount++; }
  ~Dog() { _amount--; }

  Dog* clone() override { return new Dog(*this); }
  static int amount() { return _amount; }
  void feed() override {
    setWeight(this->weight() + 0.8);
    if (weight() > 50)
      throw out_of_range("");
  }
};

int Dog::_amount = 0;


