#ifndef ADD_H
#define ADD_H
#include "math_vector.h"

MathVector add(const MathVector &u, const MathVector &v)
{
    double w[u.dimension()];
    for (int i = 0; i < u.dimension(); i++)
    {
        w[i] = u.at(i) + v.at(i);
    }
    MathVector result(u.dimension(), w);
    return result;
}

MathVector operator+(const MathVector &u, const MathVector &v)
{
    return add(u, v);
}

#endif