#include <string>

class Cat
{
private:
  std::string _name;
  double _weight;
  std::string *_toyCollections;
  int _toyAmount;

public:
  Cat(std::string name, double weight)
  {
    _name = name;
    _weight = weight;
    _toyCollections=NULL;
    _toyAmount=0;
  }

  ~Cat()
  {
    delete[] _toyCollections;
  }

  std::string getName()
  {
    return _name;
  }
  double getWeight()
  {
    return _weight;
  }

  void addNewToy(std::string toyName)
  {
    _toyAmount++;
    std::string *temp = new std::string[_toyAmount];
    for (int i = 0; i < _toyAmount - 1; i++)
    {
      temp[i] = _toyCollections[i];
    }
    temp[_toyAmount - 1] = toyName;
    delete[] _toyCollections;
    this->_toyCollections = temp;
  }

  std::string getToy(int index)
  {
    return _toyCollections[index];
  }
};
