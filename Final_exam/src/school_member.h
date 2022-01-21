#ifndef SCHOOL_MEMBER_H
#define SCHOOL_MEMBER_H
using namespace std;
#include <string>

// SchoolMember is the base class of Student and Teacher
class SchoolMember {
public:
  SchoolMember(int id, std::string const& name, std::string const& department) {
    _id = id;
    _name = name;
    _department = department;
    ++_amount;
  }
  virtual ~SchoolMember() { --_amount; }

  int id() const {return _id;}

  std::string name() const {
    return _name;
  }

  std::string department() const {
    return _department;
  }

  // 轉系
  void transfer(std::string const& department) {
    _department=department;
  }

  static int _amount;
private:
  int _id;
  std::string _name;
  std::string _department;
  
};
int SchoolMember::_amount = 0;
#endif
