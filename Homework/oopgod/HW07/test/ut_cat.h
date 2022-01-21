#include "../src/cat.h"

TEST(CatTest, Constructor)
{
    Cat cat("Oliver", 5);
    ASSERT_EQ("Oliver", cat.name());
    ASSERT_NEAR(5, cat.weight(), 0.001);
}

TEST(CatTest, WeightOutOfRange)
{
    ASSERT_THROW(Cat("Leo", 10), std::range_error);
}

TEST(CatTest, Feed)
{
    Cat cat("Oliver", 5);
    cat.feed();
    ASSERT_NEAR(5.2, cat.weight(), 0.001);
}

TEST(CatTest, FeedTooMuch)
{
    Cat cat("Leo", 5.9);
    ASSERT_THROW(cat.feed(), std::out_of_range);
}