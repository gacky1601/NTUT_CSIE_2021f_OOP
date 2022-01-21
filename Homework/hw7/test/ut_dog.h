#include "../src/dog.h"
TEST(ConstructorTest, tset1) {
    Dog dog1("fuck", 20);
    EXPECT_EQ(dog1.name(), "fuck");
    EXPECT_EQ(dog1.weight(), 20);
    dog1.feed();
    EXPECT_EQ(dog1.weight(), 20.8);
}
TEST(ConstructorTest, exception) {
    Dog dog1("fuck", 50);
    EXPECT_THROW(Dog("fuck", 51), range_error);
    EXPECT_THROW(dog1.feed(), out_of_range);
}

