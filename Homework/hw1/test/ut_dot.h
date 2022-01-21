#include "../src/dot.h"

TEST(DotTest,TwoDim1){
    int dim_u = 2;
    int dim_v = 2;
    double u[2] = {1,2};
    double v[2] = {2,3};
    ASSERT_NEAR(8, dot(u, dim_u, v, dim_v), 0.001);
}
TEST(DotTest,TwoDim2){
    int dim_u = 2;
    int dim_v = 2;
    double u[2] = {2,4};
    double v[2] = {4,5};
    ASSERT_NEAR(28, dot(u, dim_u, v, dim_v), 0.001);
}

TEST(DotTest,ThreeDim1){
    int dim_u = 3;
    int dim_v = 3;
    double u[3] = {1,2,3};
    double v[3] = {2,3,4};
    ASSERT_NEAR(20, dot(u, dim_u, v, dim_v), 0.001);
}
TEST(DotTest,ThreeDim2){
    int dim_u = 3;
    int dim_v = 3;
    double u[3] = {2,3,4};
    double v[3] = {4,5,6};
    ASSERT_NEAR(47, dot(u, dim_u, v, dim_v), 0.001);
}

TEST(DotTest,Excetion3D41){
    int dim_u = 3;
    int dim_v = 4;
    double u[3] = {1,2,3};
    double v[4] = {2,3,4,5};
    ASSERT_THROW(dot(u,dim_u,v,dim_v), std::string);
}
TEST(DotTest,Excetion3D42){
    int dim_u = 3;
    int dim_v = 4;
    double u[3] = {5,5,5};
    double v[4] = {6,7,8,9};
    ASSERT_THROW(dot(u,dim_u,v,dim_v), std::string);
}

TEST(DotTest,ExeptionNegativeD1){
    int dim_u = -1;
    int dim_v = -1;
    double u[2] = {1,2};
    double v[2] = {2,3};
    ASSERT_THROW(dot(u,dim_u,v,dim_v), std::string);
}
TEST(DotTest,ExeptionNegativeD2){
    int dim_u = -3;
    int dim_v = -2;
    double u[2] = {88,88};
    double v[2] = {99,99};
    ASSERT_THROW(dot(u,dim_u,v,dim_v), std::string);
}