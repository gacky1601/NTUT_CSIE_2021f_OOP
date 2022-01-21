#ifndef MULTI_H
#define MULTI_H
#include "math_vector.h"

double *scalarMultiply(double v[], int dim, double a)
{
    if (dim < 0)
    {
        throw std::string("undefined.");
    }
    double *u = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        u[i] = v[i] * a;
    }
    return u;
}

MathVector scalarMultiply(MathVector mv, double a)
{
    double *u = new double[mv.dimension()];
    for (int i = 0; i < mv.dimension(); i++)
    {
        u[i] = mv.at(i) * a;
    }
    MathVector result(mv.dimension(), u);
    delete[] u;
    return result; // Copy of result is returned
}

MathVector operator*(double a, MathVector mv)
{
    return scalarMultiply(mv, a);
}

#endif