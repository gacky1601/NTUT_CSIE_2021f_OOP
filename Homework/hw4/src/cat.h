#ifndef CAT_H
#define CAT_H
using namespace std;
#include "toy.h"
#include <string>
#include <vector>
class Cat
{
private:
  string _name;
  double _weight;
  vector<Toy> _toyCollections;
  // Toy *_toyCollections;
  int _toyAmount;

public:
  Cat() {}
  Cat(string name, double weight)
  {
    if (name == "")
    {
      throw string("No Name!");
    }
    if (weight < 10 || weight > 50)
    {
      throw string("Too Heavy!");
    }
    _name = name;
    _weight = weight;
    _toyAmount = 0;
    //_toyCollections = nullptr;
  }
  Cat(Cat const &other)
  {
    _name = other._name;
    _weight = other._weight;
    _toyAmount = other._toyAmount;
    _toyCollections = other._toyCollections;
    /*Toy *temp = new Toy[_toyAmount];
    for (int i = 0; i < _toyAmount-1;i++){
      temp[i] = other._toyCollections[i];
    }
    _toyCollections = temp;*/
  }
  
  Cat &operator=(Cat const &other)
  {
    if (this==&other){
      return *this;
    }
    _name = other._name;
    _weight = other._weight;
    _toyAmount = other._toyAmount;
    _toyCollections = other._toyCollections;
    return *this;
  }

  ~Cat()
  {
    // delete[] _toyCollections;
  }

  string getName()
  {
    return _name;
  }

  double getWeight() const
  {
    return _weight;
  }

  void addNewToy(Toy const toyName)
  {
    _toyAmount++;
    _toyCollections.push_back(toyName);
    // Toy *temp = new Toy[_toyAmount];
    // for (int i = 0; i < _toyAmount - 1; i++)
    // {
    //   temp[i] = _toyCollections[i];
    // }
    // temp[_toyAmount - 1] = toyName;
    // delete[] _toyCollections;
    // this->_toyCollections = temp;
  }

  Toy getToy(const int index)
  {
    if (index > _toyAmount-1 || index<0)
    {
      throw string("Out of range!");
    }
    return _toyCollections[index];
  }
  bool isHeavierThan(Cat const &other) const
  {
    return (_weight > other.getWeight());
  }
};

#endif