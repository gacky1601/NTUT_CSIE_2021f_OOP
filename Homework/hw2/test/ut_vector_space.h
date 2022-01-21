#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

TEST(VectorTest, add_TA) {
  double u[3] = {1, 2, 3};
  double v[3] = {1.5, 2.5, 3.5};

  double * result = add(u, 3, v, 3);

  EXPECT_NEAR(2.5, result[0], DELTA);
  EXPECT_NEAR(4.5, result[1], DELTA);
  EXPECT_NEAR(6.5, result[2], DELTA);

  delete [] result;   // heap allocation in 'add'
}

TEST(VectorTest, scale_TA) {
  double u[3] = {1.5, 2.5, 3.5};

  double * result = scale(u, 3, 1.2);

  EXPECT_NEAR(1.8, result[0], DELTA);
  EXPECT_NEAR(3.0, result[1], DELTA);
  EXPECT_NEAR(4.2, result[2], DELTA);

  delete [] result;  // heap allocation in 'scale'
}
