#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include "./gcd.h"
using namespace std;
class Fraction
{
private:
  int _numerator=0;
  int _denominator=1;
  char _sign='+';

public:

  Fraction()
  {
    // int _numerator = 0;
    // int _denominator = 1;
    // char _sign = '+';
  }


  Fraction(int num)
  {
    if (num >= 0)
    {
      _numerator = num;
      _denominator = 1;
      _sign = '+';
    }
    else if (num < 0)
    {
      _numerator = -num;
      _denominator = 1;
      _sign = '-';
    }
  }

  Fraction(int numerator, int denominator)
  {
    if (denominator == 0)
      throw string("undefined!");
    if (numerator * denominator > 0)
      _sign = '+';

    else if (numerator * denominator < 0)
      _sign = '-';
    if(numerator!=0||denominator!=0){
      int gcd1 = gcd(numerator, denominator);
    _numerator = abs(numerator) / gcd1;
    _denominator = abs(denominator) / gcd1;
    }
    else{
    _numerator=numerator;
    _denominator=denominator;}
  }

  int numerator() const
  {
    return _numerator;
  }

  int denominator() const
  {
    return _denominator;
  }

  char sign() const
  {
    return _sign;
  }


  std::string toString() const
  {
    string n = to_string(_numerator), d = to_string(_denominator), s, all;
    s.insert(0, 1, _sign);
    return s + n + (_denominator == 1 && _numerator!=0? "" : ("/" + d));
  }

  Fraction operator+(Fraction const &f) const
  {
    int cal =_sign==f._sign?_numerator * f._denominator + f._numerator * _denominator:_numerator * f._denominator - f._numerator * _denominator;
    Fraction temp(cal, _denominator * f._denominator);
    return temp;
  }
  Fraction operator-(Fraction const &f) const
  {
    int cal =_sign==f._sign?_numerator * f._denominator - f._numerator * _denominator:_numerator * f._denominator + f._numerator * _denominator;
    Fraction temp(cal, _denominator * f._denominator);
    return temp;
  }
  Fraction operator/(Fraction const &f) const
  {
    Fraction temp(_numerator * f._denominator , _denominator * f._numerator);
    temp._sign=_sign==f._sign?'+':'-';
    return temp;
  }
};
#endif