#include "../src/scalar_multi.h"

TEST(Vector, Scalar)
{
    double v[2] = {3, 4};
    int dim = 2;
    double a = 3.0;
    double *result = scalarMultiply(v, dim, a);
    ASSERT_NEAR(9.0, result[0], 0.001);
    ASSERT_NEAR(12.0, result[1], 0.001);
    delete[] result;
}

TEST(Vector, ScalarException)
{
    double v[2] = {3, 4};
    int dim = -1;
    double a = 3.0;
    ASSERT_THROW(scalarMultiply(v, dim, a), std::string);
}

TEST(Vector, ScalarMathVector)
{
    double v[2] = {3, 4};
    int dim = 2;
    double a = 3.0;
    MathVector mv(dim, v);
    MathVector result = scalarMultiply(mv, a); // => unknown(mv) -> mathvector copy constructor
    MathVector result1 = a * mv;
    ASSERT_NEAR(9.0, result.at(0), 0.001);
    ASSERT_NEAR(12.0, result.at(1), 0.001);
    ASSERT_NEAR(9.0, result1.at(0), 0.001);
    ASSERT_NEAR(12.0, result1.at(1), 0.001);
}