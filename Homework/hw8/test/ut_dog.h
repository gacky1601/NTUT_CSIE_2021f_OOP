#include "../src/dog.h"
#include "../src/pet.h"
#include <stdexcept>


class DogTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};

TEST_F(DogTest, ConstructorTest) {
  Dog dog1("fuck", 20);
  EXPECT_EQ(dog1.name(), "fuck");
  EXPECT_EQ(dog1.weight(), 20);
  dog1.feed();
  EXPECT_EQ(dog1.weight(), 20.8);
}

TEST_F(DogTest, ConstructorExceptionTest) {
  Dog dog1("fuck", 50);
  EXPECT_THROW(Dog("fuck", 51), range_error);
  EXPECT_THROW(Dog("fuck", 9), range_error);
  EXPECT_THROW(dog1.feed(), out_of_range);
}

TEST_F(DogTest, AmountConstructor) {
  Dog dog("Dog", 30);
  ASSERT_EQ(1, Dog::amount());
}

TEST_F(DogTest, AmountCopyConstructor) {
  Dog dog_1("Dog", 30);
  Dog dog_2 = dog_1;
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(DogTest, AmountPolymorphism) {
  Pet* pet = new Dog("Dog", 30);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Dog::amount());
  delete pet;
}