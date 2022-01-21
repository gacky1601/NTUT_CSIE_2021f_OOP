#include <gtest/gtest.h>
#include "./ut_toy.h"
#include "./ut_cat.h"

using namespace std;
int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
