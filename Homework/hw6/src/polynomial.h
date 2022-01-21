#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "term.h"
#include <vector>

using namespace std;

class Polynomial
{
private:
  std::vector<Term> _terms;
  int _degree;

public:
  Polynomial() {
    _terms = vector<Term>{ Term(0,0) };
    _degree = 0;
  }
  Polynomial(std::vector<Term> terms, int degree)
  {
    Term temp;
    _degree = degree;
    for (int i = 0;i < terms.size();i++)
      for (int j = i + 1;j < terms.size();j++)
        if (terms[i].exponent() == terms[j].exponent())
          throw string("undefined!");

    for (int i = 0; i <= _degree; i++) {
      for (int j = 0; j < terms.size(); j++) {
        if (i == terms[j].exponent()) {
          temp = terms[j];
          break;
        }
        else
          temp = Term(0, i);
      }
      _terms.push_back(temp);
    }
    stable_sort(_terms.begin(), _terms.end(), compare);
  }

  // get a term by exponent
  // If the term does not exist, return the term (0, exponent)
  Term term(int exponent) const {
    if (exponent > _degree)
      return Term(0, exponent);
    return _terms[exponent];
  }

  // get the degree
  int degree() const { return _degree; }
  // factory compare
  static bool compare(Term a, Term b) { return (a.exponent() < b.exponent()); }

  // add two polynomials
  Polynomial operator+(const Polynomial& q) const {
    int max_deg, min_deg;
    vector<Term> max_terms, min_terms, temp;
    if (_degree > q._degree) {
      max_deg = _degree, min_deg = q._degree;
      max_terms = _terms, min_terms = q._terms;
    }
    else {
      max_deg = q._degree, min_deg = _degree;
      max_terms = q._terms, min_terms = _terms;
    }
    for (int i = 0; i <= max_deg;i++) {
      if (i <= min_deg)
        temp.push_back(_terms[i] + q._terms[i]);
      else
        temp.push_back(max_terms[i]);
    }
    for (int i = max_deg;i >= 0;i--)
      if (temp[i].coefficient() != 0) {
        max_deg = i;
        break;
      }
    return Polynomial(temp, max_deg);
  }

  // multiply by a term
  Polynomial operator*(Term t) const {
    vector<Term> temp;
    int deg = _degree + t.exponent();
    for (int i = 0;i <= _degree;i++) {
      temp.push_back(_terms[i] * t);
    }
    return Polynomial(temp, deg);
  }

  // multiply by another Polynomial
  Polynomial operator*(Polynomial const& mult) const {
    Polynomial temp(_terms, _degree);
    Polynomial sum;
    for (int i = 0;i <= mult._degree;i++) 
      sum = sum + temp * mult._terms[i];
    return sum;
  }
};

#endif
