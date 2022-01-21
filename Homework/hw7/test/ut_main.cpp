#include <gtest/gtest.h>
using namespace std;
#include <string>
#include <vector>
#include "../src/pet.h"
#include "ut_cat.h"
#include "ut_dog.h"
#include "ut_algo.h"

using namespace std;
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
