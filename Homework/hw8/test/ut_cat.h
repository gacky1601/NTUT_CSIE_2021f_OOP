#include "../src/cat.h"
#include "../src/pet.h"



class CatTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }
  
  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }
  const double DELTA = 0.001;
};

TEST_F(CatTest, AmountConstructor) {
  Cat cat("Cat", 3);
  ASSERT_EQ(1, Cat::amount());
}

TEST_F(CatTest, AmountCopyConstructor) {
  Cat cat_1("Cat", 3);
  Cat cat_2 = cat_1;
  ASSERT_EQ(2, Cat::amount());
}

TEST_F(CatTest, AmountPolymorphism) {
  Pet* pet = new Cat("Cat", 3);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Cat::amount());
  delete pet;
}

TEST_F(CatTest, ConstructorTest) {
  Cat cat1("fuck", 5);
  EXPECT_EQ(cat1.name(), "fuck");
  EXPECT_EQ(cat1.weight(), 5);
  cat1.feed();
  EXPECT_EQ(cat1.weight(), 5.2);
}

TEST_F(CatTest, ConstructorExceptionTest) {
  Cat cat1("fuck", 6);
  EXPECT_THROW(Cat("fuck", 10), range_error);
  EXPECT_THROW(Cat("fuck", 1), range_error);
  EXPECT_THROW(cat1.feed(), out_of_range);
}
