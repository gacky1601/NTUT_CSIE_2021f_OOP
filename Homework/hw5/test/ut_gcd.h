#include "../src/gcd.h"
class GCDTest : public ::testing::Test
{
protected:
    int num1a, num1b;
    int gcd1;
    void SetUp() override
    {
        num1a = 12, num1b = 24;
        gcd1= gcd(num1a, num1b);
    }
};

TEST_F(GCDTest, test1)
{
    EXPECT_EQ(gcd1, 12);
}