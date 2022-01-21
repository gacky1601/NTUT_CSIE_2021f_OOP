#include <gtest/gtest.h>
#include "length_test.h"
#include "scalar_multi_test.h"
#include "vector_test.h"
#include "polygon_test.h"
#include "app_test.h"
#include "exchange_test.h"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}