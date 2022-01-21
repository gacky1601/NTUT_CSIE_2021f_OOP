#ifndef TOY_H
#define TOY_H 
using namespace std;
#include <string>
#include <vector>
class Toy
{
public:
    Toy() {}
    Toy(string name)
    {
        _name = name;
    }

    string getName() const
    {
        return _name;
    }

private:
    string _name;
};
#endif