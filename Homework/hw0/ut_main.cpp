#include <gtest/gtest.h>
#include "HelloWorld.h"

TEST(HELLOWORLD,PrintHelloWorld){
    string output = PrintHelloWorld();
    string compare = "Hello World! \n";
    ASSERT_EQ(output, compare);
}

int main(int argc, char **argv){
    testing ::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}