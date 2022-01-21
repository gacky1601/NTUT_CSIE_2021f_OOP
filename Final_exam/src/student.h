#ifndef STUDENT_H
#define STUDENT_H

#include <numeric>  // std::accumulate
#include <stdexcept>  // std::out_of_range, std::range_error
#include <string>
#include <vector>

#include "school_member.h"

class Student :public SchoolMember {
public:
  Student(int const id, std::string const& name, std::string const& department = "Mechanical & Electrical Engineering") :SchoolMember(id, name, department)
  {}
  ~Student() {}
  void addScore(double const score) {
    _scores.push_back(score);
  }

  double getScore(int const number_of_test) const {
    if (number_of_test > _scores.size() - 1 || number_of_test < 1)
      throw out_of_range("ERROR: NO_SUCH_NUMBER_OF_TEST");
    return _scores[number_of_test];
  }

  double scoreAverage() const {
    double avg=0;
    if (_scores.size() == 1)
      throw range_error("ERROR: NO_SCORE");
    for (int i = 0;i < _scores.size();i++)
      avg += _scores[i];
    avg /= (_scores.size() - 1);
    return avg;
  }

private:
  // store student's hw scores
  vector<double> _scores = { 0 };
};

#endif
