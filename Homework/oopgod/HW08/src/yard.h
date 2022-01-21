#pragma once

#include <vector>

#include "pet.h"

class Yard
{
private:
  std::vector<Pet*> _pets;

public:
  Yard() = default;

  Yard(Yard const& other)
  {
    for (Pet* p : other._pets)
      _pets.push_back(p->clone());
  }

  Yard& operator=(Yard const& other)
  {
    if (&other != this)
    {
      for (Pet* p : _pets)
        delete p;
      _pets.clear();
      for (Pet* p : other._pets)
        _pets.push_back(p->clone());
    }
    return *this;
  }

  ~Yard()
  {
    for (Pet* p : _pets)
      delete p;
  }

  void addPet(Pet* pet)
  {
    _pets.push_back(pet);
  }

  template <typename Condition>
  std::vector<Pet*> getPetWithCondition(Condition cond) {
    std::vector<Pet*> pets_in_cond;
    for (Pet* pet : _pets)
      if (cond(pet))
        pets_in_cond.push_back(pet);
    return pets_in_cond;
  }
};