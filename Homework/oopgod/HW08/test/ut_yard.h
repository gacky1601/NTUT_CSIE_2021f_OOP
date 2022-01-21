#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/yard.h"

class YardTest : public ::testing::Test
{
protected:
  const double DELTA = 0.001;

  void SetUp() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }
};

TEST_F(YardTest, GetPetWithConditionWeightByLambda)
{
  Yard yard;
  std::vector<Pet *> result;
  yard.addPet(new Cat("Oliver", 5));
  yard.addPet(new Dog("Lucky", 15));
  yard.addPet(new Cat("Leo", 3));
  yard.addPet(new Dog("Mickey", 35));
  result = yard.getPetWithCondition([](Pet *p)
                                    { return p->weight() < 10; });
  ASSERT_EQ("Oliver", result.at(0)->name());
  ASSERT_EQ("Leo", result.at(1)->name());
}

bool cond(Pet *p) { return p->kind() == "DOG"; }
TEST_F(YardTest, GetPetWithConditionKindByFunction)
{
  Yard yard;
  std::vector<Pet *> result;
  yard.addPet(new Cat("Oliver", 5));
  yard.addPet(new Dog("Lucky", 15));
  yard.addPet(new Cat("Leo", 3));
  yard.addPet(new Dog("Mickey", 35));
  result = yard.getPetWithCondition(cond);
  ASSERT_EQ("Lucky", result.at(0)->name());
  ASSERT_EQ("Mickey", result.at(1)->name());
}

class Condition
{
public:
  bool operator()(Pet *p) { return p->weight() == 15; }
};
TEST_F(YardTest, GetPetWithConditionWeightByFunctor)
{
  Yard yard;
  std::vector<Pet *> result;
  Condition cond;
  yard.addPet(new Cat("Oliver", 5));
  yard.addPet(new Dog("Lucky", 15));
  yard.addPet(new Cat("Leo", 3));
  yard.addPet(new Dog("Mickey", 35));
  result = yard.getPetWithCondition(cond);
  ASSERT_EQ("Lucky", result.at(0)->name());
}

TEST_F(YardTest, CopyConstructor)
{
  Yard y1;
  std::vector<Pet *> result;
  y1.addPet(new Cat("Oliver", 5));
  y1.addPet(new Dog("Lucky", 15));
  Yard y2(y1);
  result = y2.getPetWithCondition([](Pet *p)
                                  { return p->kind() == "CAT"; });
  ASSERT_EQ("Oliver", result.at(0)->name());
  ASSERT_EQ(4, Pet::amount());
  ASSERT_EQ(2, Cat::amount());
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(YardTest, CopyAssignment)
{
  Yard y1, y2;
  std::vector<Pet *> result;
  y1.addPet(new Cat("Oliver", 5));
  y1.addPet(new Dog("Lucky", 15));
  y2 = y1;
  result = y2.getPetWithCondition([](Pet *p)
                                  { return p->kind() == "CAT"; });
  ASSERT_EQ("Oliver", result.at(0)->name());
  ASSERT_EQ(4, Pet::amount());
  ASSERT_EQ(2, Cat::amount());
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(YardTest, SelfAssignment)
{
  Yard y1;
  std::vector<Pet *> result;
  y1.addPet(new Cat("Oliver", 5));
  y1.addPet(new Dog("Lucky", 15));
  y1 = y1;
  result = y1.getPetWithCondition([](Pet *p)
                                  { return p->kind() == "CAT"; });
  ASSERT_EQ("Oliver", result.at(0)->name());
  ASSERT_EQ(2, Pet::amount());
  ASSERT_EQ(1, Cat::amount());
  ASSERT_EQ(1, Dog::amount());
}