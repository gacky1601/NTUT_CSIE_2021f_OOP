#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/pet.h"
#include "../src/yard.h"

class YardTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }
  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }
  const double DELTA = 0.001;
};

TEST_F(YardTest, SelfAssignment) {
  Yard myyard;
  myyard.addPet(new Cat("Micky", 3));
  myyard.addPet(new Cat("Rich", 3.5));
  myyard = myyard;
  EXPECT_EQ(Pet::amount(), 2);
}
TEST_F(YardTest, CopyConstructorTest)
{
  Yard myyard;
  myyard.addPet(new Cat("Micky", 3));
  Yard newyard(myyard);
  EXPECT_EQ(Pet::amount(), 2);
}

TEST_F(YardTest, CopyAssignmentTest)
{
  Yard myyard, heryard;
  myyard.addPet(new Cat("Micky", 3));
  heryard = myyard;
  EXPECT_EQ(Pet::amount(), 2);
}
class Condition {
public:
  bool operator() (Pet* pet) { return pet->weight() == 3; }
};
TEST_F(YardTest, GetPetWithConditionWeightByFunctor) {
  Yard myyard;
  vector <Pet*> result;
  Condition cond;
  myyard.addPet(new Cat("Micky", 3));
  myyard.addPet(new Cat("Rich", 3.5));
  result = myyard.getPetWithCondition(cond);
  EXPECT_EQ("Micky", result.at(0)->name());
}

bool cond(Pet* p) { return p->kind() == "CAT"; }
TEST_F(YardTest, GetPetWithConditionWeightByFunction) {
  Yard myyard;
  vector <Pet*> result;
  myyard.addPet(new Dog("Micky", 15));
  myyard.addPet(new Cat("Rich", 3.5));
  result = myyard.getPetWithCondition(cond);
  EXPECT_EQ("Rich", result.at(0)->name());
}

TEST_F(YardTest, GetPetWithConditionWeightByLambda)
{
  Yard myyard;
  vector <Pet*> result;
  myyard.addPet(new Dog("Micky", 15));
  myyard.addPet(new Cat("Rich", 3.5));
  result = myyard.getPetWithCondition([](Pet* pet) {return pet->weight() < 16;});
  EXPECT_EQ("Micky", result[0]->name());
  EXPECT_EQ("Rich", result[1]->name());
}