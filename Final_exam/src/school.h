#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>

#include "school_member.h"

class School {
public:
  School() = default;

  void addSchoolMember(SchoolMember* const member) {
    _schoolmembers.push_back(member);
  }

  template<typename Condition>
  std::vector<SchoolMember*> getSchoolMemberWithCondition(Condition cond) {
    std::vector<SchoolMember*> school_member_in_cond;
    for (SchoolMember* sm : _schoolmembers)
      if (cond(sm))
        school_member_in_cond.push_back(sm);
    return school_member_in_cond;
  }

private:
  vector <SchoolMember*> _schoolmembers;
  School(School const& other) {
    _schoolmembers = other._schoolmembers;
  }
  School& operator=(School const& other) {
    if (&other != this)
      _schoolmembers = other._schoolmembers;
    return *this;
  }
};

#endif
