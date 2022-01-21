#include "../src/algo.h"
using namespace pet_comp;
TEST(algo, functionTest) {
    Cat c1 = Cat("a", 3);
    Cat c2 = Cat("trrtwy", 4);
    Dog d1 = Dog("sajd", 25);
    Dog d2 = Dog("dfojsdaofa", 23);
    vector <Pet*> list1 = { &c1,&c2 ,&d1,&d2 };
    EXPECT_EQ(maxPet(list1.begin(), list1.end(), largerWeight)[0]->weight(), 25);
    EXPECT_EQ(maxPet(list1.begin(), list1.end(), longerName)[0]->name(), "dfojsdaofa");
}
