#include "../src/toy.h"
#include <gtest/gtest.h>
TEST(Toy,getName)
{
    Toy toy1("CheeseBurger");
    EXPECT_EQ(toy1.getName(), "CheeseBurger");
}