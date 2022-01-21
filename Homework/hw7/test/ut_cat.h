#include "../src/cat.h"
TEST(Cat, ConstructorTest) {
    Cat cat1("fuck", 5);
    EXPECT_EQ(cat1.name(), "fuck");
    EXPECT_EQ(cat1.weight(), 5);
    cat1.feed();
    EXPECT_EQ(cat1.weight(), 5.2);
}
TEST(Cat, ConstructorExceptionTest) {
    Cat cat1("fuck", 6);
    EXPECT_THROW(Cat ("fuck", 10), range_error);
    EXPECT_THROW(cat1.feed(), out_of_range);
}