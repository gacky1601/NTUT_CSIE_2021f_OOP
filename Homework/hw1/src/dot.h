#ifndef DOT_H
#define DOT_H
#include <string>
double dot(double *u, int dim_u, double *v, int dim_v) {

  double result = 0;
  if (dim_u != dim_v || dim_u < 0 || dim_v < 0) {
    throw std::string("undefined");
  }

    for (int i = 0; i < dim_v;i++){
      result = result + u[i] * v[i];
      }
    return result;
} 

#endif // end of include guard: DOT_H
