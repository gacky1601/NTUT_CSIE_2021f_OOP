#include <vector>

#include "../src/algo.h"
#include "../src/cat.h"
#include "../src/dog.h"

class AlgoTest : public ::testing::Test
{
protected:
    std::vector<Pet *> pets;
    std::vector<Pet *>::iterator pet;

    void SetUp() override
    {
        pets.push_back(new Cat("Oliver", 5));
        pets.push_back(new Dog("Lucky", 15));
        pets.push_back(new Cat("Leo", 3));
        pets.push_back(new Dog("Mickey", 35));
    }

    void TearDown() override
    {
        for (Pet *p : pets)
            delete p;
    }
};

TEST_F(AlgoTest, MaxWeight)
{
    pet = maxPet(pets.begin(), pets.end(), pet_comp::largerWeight);
    ASSERT_EQ("Mickey", (*pet)->name());
    ASSERT_NEAR(35, (*pet)->weight(), 0.001);
}

TEST_F(AlgoTest, MaxName)
{
    pet = maxPet(pets.begin(), pets.end(), pet_comp::longerName);
    ASSERT_EQ("Oliver", (*pet)->name());
    ASSERT_NEAR(5, (*pet)->weight(), 0.001);
}