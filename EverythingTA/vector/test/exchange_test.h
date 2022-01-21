#include "../src/exchange.h"
#include "../src/math_vector.h"

TEST(Exchange, IntExchange) {
    int a = 10;
    int b = 15;
    exchange(a, b);
    ASSERT_EQ(15, a);
    ASSERT_EQ(10, b);
}
TEST(Exchange, DoubleExchange) {
    double a = 10;
    double b = 15;
    exchange(a, b);
    ASSERT_NEAR(15, a, 0.01);
    ASSERT_NEAR(10, b, 0.01);
}

TEST(Exchange, MathVectorExchange) {
    double i[2] = {1.0, 2.0};
    double j[2] = {5.0, 6.0};

    MathVector a(2, i);
    MathVector b(2, j);
    exchange(a, b);
    ASSERT_NEAR(5, a.at(0), 0.01);
    ASSERT_NEAR(6, a.at(1), 0.01);
    ASSERT_NEAR(1, b.at(0), 0.01);
    ASSERT_NEAR(2, b.at(1), 0.01);
}

bool cmp(int a, int b) {
    return a > b;
}

TEST(Exchange, IntExchangeCompare) {
    int a = 10;
    int b = 15;
    exchange(a, b, cmp);
    ASSERT_EQ(10, a);
    ASSERT_EQ(15, b);
}