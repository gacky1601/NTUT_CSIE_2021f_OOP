#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <algorithm>

#include "term.h"

class Polynomial
{
public:
  Polynomial() {}

  Polynomial(std::vector<Term> terms, int degree)
  {
    std::stable_sort(terms.begin(), terms.end(), [](Term t1, Term t2)
      { return t1.exponent() < t2.exponent(); });
    for (int i = 0; i < terms.size() - 1; i++)
      if (terms.at(i).exponent() == terms.at(i + 1).exponent())
        throw std::string("undefine");
    for (int i = 0; i <= degree; i++)
      if (terms.at(i).exponent() != i)
        terms.insert(terms.begin() + i, Term(0, i));
    while (degree > 0 && terms.at(degree).coefficient() == 0)
      degree--;

    _terms = terms;
    _degree = degree;
  }

  // get a term by exponent
  // If the term does not exist, return the term (0, exponent)
  Term term(int exponent) const
  {
    if (exponent > _degree || exponent < 0)
      return Term(0, exponent);
    return _terms.at(exponent);
  }

  // get the degree
  int degree() const
  {
    return _degree;
  }

  // add two polynomials
  Polynomial operator+(const Polynomial& q) const
  {
    int degree = std::max(_degree, q._degree), i = 0;
    std::vector<Term> terms(degree + 1);

    for (; i <= _degree && i <= q._degree; i++)
      terms.at(i) = _terms.at(i) + q._terms.at(i);
    for (i; i <= degree; i++)
      terms.at(i) = _degree == degree ? _terms.at(i) : q._terms.at(i);

    return Polynomial(terms, degree);
  }

  // multiply by a term
  Polynomial operator*(Term t) const
  {
    int degree = _degree + t.exponent();
    std::vector<Term> terms(degree + 1);
    for (int i = 0; i <= degree; i++)
      terms.at(i) = Term(0, i);

    for (Term term : _terms)
      terms.at(term.exponent() + t.exponent()) += term * t;

    return Polynomial(terms, degree);
  }

  // multiply by another Polynomial
  Polynomial operator*(const Polynomial& q) const
  {
    int degree = _degree + q._degree;
    std::vector<Term> terms(degree + 1);
    for (int i = 0; i <= degree; i++)
      terms.at(i) = Term(0, i);

    for (Term t1 : _terms)
      for (Term t2 : q._terms)
        terms.at(t1.exponent() + t2.exponent()) += t1 * t2;

    return Polynomial(terms, degree);
  }

private:
  std::vector<Term> _terms;
  int _degree;
};

#endif
