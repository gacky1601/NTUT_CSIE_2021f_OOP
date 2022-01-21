#include "../src/dog.h"

class DogTest : public ::testing::Test
{
protected:
  const double DELTA = 0.001;

  void SetUp() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }
};

TEST_F(DogTest, AmountConstructor)
{
  Dog dog("Dog", 30);
  ASSERT_EQ(1, Dog::amount());
}

TEST_F(DogTest, AmountCopyConstructor)
{
  Dog dog_1("Dog", 30);
  Dog dog_2 = dog_1;
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(DogTest, AmountPolymorphism)
{
  Pet *pet = new Dog("Dog", 30);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Dog::amount());
  delete pet;
}

TEST_F(DogTest, Constructor)
{
  Dog dog("Lucky", 15);
  ASSERT_EQ("DOG", dog.kind());
  ASSERT_EQ("Lucky", dog.name());
  ASSERT_NEAR(15, dog.weight(), 0.001);
}

TEST_F(DogTest, WeightOutOfRange)
{
  ASSERT_THROW(Dog("Mickey", 60), std::range_error);
}

TEST_F(DogTest, Feed)
{
  Dog dog("Lucky", 15);
  dog.feed();
  ASSERT_NEAR(15.8, dog.weight(), 0.001);
}

TEST_F(DogTest, FeedTooMuch)
{
  Dog dog("Mickey", 49.5);
  ASSERT_THROW(dog.feed(), std::out_of_range);
}