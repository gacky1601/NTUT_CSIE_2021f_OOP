#include "../src/length.h"

TEST(Vector, Length) {
    double v[2] = {3, 4};
    int len = 2;
    double result = length(v, len);
    ASSERT_NEAR(5.0, result, 0.001);
}

TEST(Vector, MathVectorLength) {
    double v[2] = {3, 4};
    int len = 2;
    MathVector mv(len, v);
    double result = length(mv);
    ASSERT_NEAR(5.0, result, 0.001);
}