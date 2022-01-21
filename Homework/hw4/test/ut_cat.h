#include "../src/cat.h"
#include "../src/toy.h"
#include <gtest/gtest.h>

TEST(Cat, NoNameException)
{
    ASSERT_THROW(Cat pussy("", 45), string);
}
TEST(Cat, WeightException)
{
    EXPECT_THROW(Cat pussy("Cat", 60), string);
    EXPECT_THROW(Cat pussy1("Cat1", 5), string);
}

TEST(Cat, CopyConstructor)
{
    Cat pussy("Cat", 20);
    Cat pussy1(pussy);
    ASSERT_EQ(pussy.getWeight(),pussy1.getWeight());
}

TEST(Cat, CopyAssignment)
{
    Cat pussy("Cat", 20);
    Cat pussy1 = pussy;
    ASSERT_EQ(pussy.getWeight(),pussy1.getWeight());
}

TEST(Cat, addNewToy)
{
    Cat pussy1("Apple", 40);
    Toy t1("CheeseBurger");
    Toy t2("FrenchFries");
    Toy t3("Eggroll");
    pussy1.addNewToy(t1);
    pussy1.addNewToy(t2);
    pussy1.addNewToy(t3);
    EXPECT_EQ("Eggroll", pussy1.getToy(2).getName());
}


TEST(Cat, getToy)
{
    Cat pussy("Apple", 40);
    Toy t1("FoodPanda");
    Toy t2("Uber Eats");
    Toy t3("Lalamove");
    pussy.addNewToy(t1);
    pussy.addNewToy(t2);
    pussy.addNewToy(t3);
    EXPECT_EQ("FoodPanda", pussy.getToy(0).getName());
    EXPECT_EQ("Uber Eats", pussy.getToy(1).getName());
    EXPECT_EQ("Lalamove", pussy.getToy(2).getName());
}
TEST(Cat, getToyException)
{
    Cat pussy("Apple", 50);
    Toy t1("FoodPanda");
    Toy t2("Uber Eats");
    Toy t3("Lalamove");
    pussy.addNewToy(t1);
    pussy.addNewToy(t2);
    pussy.addNewToy(t3);
    EXPECT_THROW(pussy.getToy(3).getName(), string);
}

TEST(Cat, isHeavierThan)
{
    Cat pussy("Apple", 40);
    Cat pussy1("Cherry", 30);
    EXPECT_TRUE(pussy.isHeavierThan(pussy1));
    EXPECT_FALSE(pussy1.isHeavierThan(pussy));
}


