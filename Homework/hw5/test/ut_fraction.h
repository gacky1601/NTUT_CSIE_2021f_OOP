#include "../src/fraction.h"
#include "../src/gcd.h"

class FractionTest: public ::testing::Test
{
protected:
    Fraction f1,f2,f3,f4,f5,f6;
    void SetUp() override
    {
        f1=Fraction(3);
        f2=Fraction(4,3);
        f3=Fraction(8,8);
        f4=Fraction(-1,6);
        f5=Fraction(8,2);
    }
};

TEST_F(FractionTest,ConstructorTest){
    EXPECT_EQ(f1.toString(),"+3");
    EXPECT_EQ(f2.toString(),"+4/3");
    EXPECT_EQ(f3.toString(),"+1");
    EXPECT_EQ(f4.toString(),"-1/6");
    EXPECT_EQ(f5.toString(),"+4");
    EXPECT_EQ(f6.toString(),"+0/1");
    EXPECT_EQ((f5+f4).toString(),"+23/6");
    EXPECT_EQ((f5-f4).toString(),"+25/6");
    EXPECT_EQ((f5/f4).toString(),"-24");
    
}
TEST_F(FractionTest,ExceptionTest){
    EXPECT_THROW(Fraction(1,0),string);
}

TEST_F(FractionTest,MemberFunctionTest){
    EXPECT_EQ(f1.numerator(),3);
    EXPECT_EQ(f2.denominator(),3);
    EXPECT_EQ(f3.sign(),'+');
    EXPECT_EQ(f4.sign(),'-');

}