#pragma once
#include <vector>
#include "pet.h"

class Yard {
private:
  std::vector<Pet*> _pets;

public:
  Yard() = default;
  Yard(Yard& other) {
    for (Pet* pet : other._pets)
      addPet(pet->clone());
  }
  ~Yard() {
    for (Pet* pet : _pets)
      delete pet;
  }
  Yard& operator= (const Yard& other) {
    if (&other != this)
      for (int i = 0;i < other._pets.size();i++)
        addPet(other._pets[i]->clone());
    return *this;
  }
  void addPet(Pet* pet) { _pets.push_back(pet); }
  template<typename Condition>
  std::vector<Pet*> getPetWithCondition(Condition cond) {
    std::vector<Pet*> pets_in_cond;
    for (Pet* pet : _pets)
      if (cond(pet))
        pets_in_cond.push_back(pet);
    return pets_in_cond;
  }
};



