#include "../src/cat.h"
#include <string>
#include <gtest/gtest.h>

// add your test here
TEST(Cat,getName1){
    Cat ct1("Apple",50);
    EXPECT_EQ("Apple",ct1.getName());
    
}
TEST(Cat,getName2){
    Cat ct2("Linda",45);
    EXPECT_EQ("Linda",ct2.getName());

}

TEST(Cat,getWeight1){
    Cat ct1("Apple",50);
    EXPECT_EQ(50,ct1.getWeight());
}
TEST(Cat,getWeight2){
    Cat ct2("Linda",45);
    EXPECT_EQ(45,ct2.getWeight());
}

TEST(Cat,addNewToy1){
    Cat ct1("Apple",50);
    ct1.addNewToy("CheeseBurger");
    ct1.addNewToy("Sushi");
    ct1.addNewToy("Eggroll");
    EXPECT_EQ("Eggroll",ct1.getToy(2));


}

TEST(Cat,addNewToy2){
    Cat ct2("Linda",45);
    ct2.addNewToy("Pizza");
    ct2.addNewToy("Fish");
    ct2.addNewToy("BubbleTea");
    EXPECT_EQ("Pizza",ct2.getToy(0));
}

TEST(Cat,getToy1){
    Cat ct1("Apple",50);
    ct1.addNewToy("CheeseBurger");
    ct1.addNewToy("Sushi");
    ct1.addNewToy("Eggroll");
    EXPECT_EQ("Eggroll",ct1.getToy(2));
}

TEST(Cat,getToy2){
    Cat ct2("Linda",45);
    ct2.addNewToy("Pizza");
    ct2.addNewToy("Fish");
    ct2.addNewToy("BubbleTea");
    EXPECT_EQ("Pizza",ct2.getToy(0));
}

