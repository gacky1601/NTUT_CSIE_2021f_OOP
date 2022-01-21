#include "../src/cat.h"

class CatTest : public ::testing::Test
{
protected:
  const double DELTA = 0.001;

  void SetUp() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }

  void TearDown() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }
};

TEST_F(CatTest, AmountConstructor)
{
  Cat cat("Cat", 3);
  ASSERT_EQ(1, Cat::amount());
}

TEST_F(CatTest, AmountCopyConstructor)
{
  Cat cat_1("Cat", 3);
  Cat cat_2 = cat_1;
  ASSERT_EQ(2, Cat::amount());
}

TEST_F(CatTest, AmountPolymorphism)
{
  Pet *pet = new Cat("Cat", 3);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Cat::amount());
  delete pet;
}

TEST_F(CatTest, Constructor)
{
  Cat cat("Oliver", 5);
  ASSERT_EQ("CAT", cat.kind());
  ASSERT_EQ("Oliver", cat.name());
  ASSERT_NEAR(5, cat.weight(), 0.001);
}

TEST_F(CatTest, WeightOutOfRange)
{
  ASSERT_THROW(Cat("Leo", 10), std::range_error);
}

TEST_F(CatTest, Feed)
{
  Cat cat("Oliver", 5);
  cat.feed();
  ASSERT_NEAR(5.2, cat.weight(), 0.001);
}

TEST_F(CatTest, FeedTooMuch)
{
  Cat cat("Leo", 5.9);
  ASSERT_THROW(cat.feed(), std::out_of_range);
}