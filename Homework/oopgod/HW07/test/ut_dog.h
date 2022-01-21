#include "../src/dog.h"

#include "../src/cat.h"

TEST(DogTest, Constructor)
{
    Dog dog("Lucky", 15);
    ASSERT_EQ("Lucky", dog.name());
    ASSERT_NEAR(15, dog.weight(), 0.001);
}

TEST(DogTest, WeightOutOfRange)
{
    ASSERT_THROW(Dog("Mickey", 60), std::range_error);
}

TEST(DogTest, Feed)
{
    Dog dog("Lucky", 15);
    dog.feed();
    ASSERT_NEAR(15.8, dog.weight(), 0.001);
}

TEST(DogTest, FeedTooMuch)
{
    Dog dog("Mickey", 49.5);
    ASSERT_THROW(dog.feed(), std::out_of_range);
}