#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H
#include "math_vector.h"

double *add(double u[], int dim_u, double v[], int dim_v)
{
    if (dim_u != dim_v || dim_u < 0 || dim_v < 0||dim_v==0)
    {
        throw std::string("undefined.");
    }
    double *w = new double[dim_u];
    for (int i = 0; i < dim_u; i++)
    {
        w[i] = u[i] + v[i];
    }
    return w;
}

double *scale(double v[], int dim_v, double a)
{
    if (dim_v < 0 ||dim_v==0)
    {
        throw std::string("undefined.");
    }
    double *u = new double[dim_v];
    for (int i = 0; i < dim_v; i++)
    {
        u[i] = v[i] * a;
    }
    return u;
}

#endif