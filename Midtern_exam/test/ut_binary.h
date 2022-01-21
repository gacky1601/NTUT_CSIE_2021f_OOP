#include "../src/binary.h"

TEST(Binary_constructor, Sample1){
  int bits[8]={1,0,1,0,1,0,1,0};
  Binary a(bits,8);
  EXPECT_EQ("10101010",a.toString());
}

// TEST(Binary_constructor, Sample2){
//   int ab[6]={1,1,1,0,1,0};
//   Binary a(ab,6);
//   Binary b(a);
//   EXPECT_EQ("111010",a.toString());
//   EXPECT_EQ("111010",b.toString());
// }


TEST(Binary_right_shift, Sample3){
  int ab[4]={1,1,1,0};
  Binary a(ab, 4);
  a>>2;
  EXPECT_EQ("0011",a.toString());
  a>>4;
  EXPECT_EQ("0000",a.toString());
}

TEST(Binary_right_shift, Sample4){
  Binary a;
  EXPECT_ANY_THROW(a>>1);
}


