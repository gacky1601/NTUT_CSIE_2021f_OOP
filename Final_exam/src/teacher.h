#ifndef TEACHER_H
#define TEACHER_H

#include <algorithm>  // std::find_if
#include <stdexcept>  // std::domain_error, std::range_error
#include <string>
#include <vector>
#include "school_member.h"
#include "student.h"

class Teacher :public SchoolMember {
public:
  Teacher(int const id, std::string const& name, std::string const& department = "Mechanical & Electrical Engineering") :SchoolMember(id, name, department) {

  }
  ~Teacher() override{}
  // Don't have to handle duplicate ids.
  void addStudent(Student const& stu) {
    if (stu.department() != department())
      throw domain_error("ERROR: NOT_IN_THE_SAME_DEPARTMENT");
    _students.push_back(stu);
  }

  Student getStudentById(int const id) const {
    // If you don't know how to use the capture clause, which is the [],
    // you can use a functor and set the id into it before passing.
    for (Student stu:_students)
      if (stu.id() == id)
        return stu;
    throw range_error("ERROR: STUDENT_NOT_EXIST");
  }

private:
  vector <Student> _students;
  // store this teacher's students
};

#endif
