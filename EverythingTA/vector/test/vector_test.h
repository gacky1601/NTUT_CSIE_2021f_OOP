#include "../src/math_vector.h"
#include "../src/triangle.h"
#include "../src/shape.h"
#include <vector>
//#include "../src/add.h"

class MathVectorTest : public ::testing::Test {
protected:
    int dim;
    double v[2];
    double u[2];
    double w[2];
    MathVector mv;
    MathVector mv1;
    MathVector mv2;
    void SetUp() override {
        dim = 2;
        v[0] = 3;
        v[1] = 4;
        u[0] = 49;
        u[1] = 420;
        w[0] = 5;
        w[1] = 12;
        mv2 = MathVector(dim, w);
        mv1 = MathVector(dim, u);
        mv = MathVector(dim, v);
    }
};

TEST_F(MathVectorTest, toString){
    ASSERT_EQ(mv.toString(),"3 4");
}

TEST_F(MathVectorTest, Vector)
{
    std::vector<Triangle> tV(10);
    std::vector<Triangle> tV1;
    
    Triangle t(mv, mv1, mv2);
    tV1.push_back(t);
    // tV1.pop_back();
    tV1.at(0); // equals to tV1[0]
    ASSERT_NEAR(tV1.at(0).perimeter(), 837.147, 0.001);
}

TEST_F(MathVectorTest, triangleShape) {
    Shape *s = new Triangle(mv, mv1, mv2, "T");
    ASSERT_NEAR(s -> perimeter(), 837.147, 0.001);
    ASSERT_EQ("Triangle:: T", s -> getName());
    delete s;
}

TEST_F(MathVectorTest, MathVector)
{
    ASSERT_NEAR(5, mv.length(), 0.01);
}

TEST_F(MathVectorTest, MathVectorIndex)
{
    ASSERT_NEAR(3, mv.at(0), 0.01);
    ASSERT_NEAR(4, mv.at(1), 0.01);
}

TEST_F(MathVectorTest, MathVectorSet)
{
    mv.setIndex(0, 4);
    mv.setIndex(1, 3);
    ASSERT_NEAR(4, mv.at(0), 0.01);
    ASSERT_NEAR(3, mv.at(1), 0.01);
}

TEST_F(MathVectorTest, MathVectorSetException)
{
    ASSERT_THROW(mv.setIndex(2, 4), std::string);
}

TEST_F(MathVectorTest, AddMathVector)
{
    double v[2] = {3, 4};
    double v1[2] = {5, 6};
    int dim = 2;
    MathVector mv(dim, v);
    MathVector mv1(dim, v1);

    MathVector result = mv + mv1;
    ASSERT_NEAR(8.0, result.at(0), 0.001);
    ASSERT_NEAR(10.0, result.at(1), 0.001);
    ASSERT_EQ(2, result.dimension());
}

/*TEST_F(Vector, AddMathVectorDiff)
{
    double v[2] = {3, 4};
    double v1[3] = {5, 6, 7};
    int dim = 2;
    int dim1 = 3;
    MathVector mv(dim, v);
    MathVector mv1(dim1, v1);

    MathVector result = add(mv, mv1);
    ASSERT_NEAR(8.0, result.at(0), 0.001);
    ASSERT_NEAR(10.0, result.at(1), 0.001);
    ASSERT_NEAR(7.0, result.at(2), 0.001);
    ASSERT_EQ(2, result.dimension());
}*/

TEST_F(MathVectorTest, MathVectorAssignment)
{
    double v[2] = {3, 4};
    int dim = 2;
    MathVector mv(dim, v), mv1, mv2;
    mv1 = mv2 = mv;
    ASSERT_NEAR(3.0, mv1.at(0), 0.001);
    ASSERT_NEAR(4.0, mv1.at(1), 0.001);
    ASSERT_EQ(2, mv1.dimension());
}

TEST(Triangle, Constructor)
{
    double u[2] = {0, 3};
    double w[2] = {4, 0};
    double v[2] = {0, 0};
    int dim = 2;
    MathVector mv(dim, u), mv1(dim, w), mv2(dim, v);
    Triangle t(mv, mv1, mv2);
    ASSERT_NEAR(12.0, t.perimeter(), 0.001);
}

TEST(Triangle, toString)
{
    double u[2] = {0, 3};
    double w[2] = {4, 0};
    double v[2] = {0, 0};
    int dim = 2;
    MathVector mv(dim, u), mv1(dim, w), mv2(dim, v);
    Triangle t(mv, mv1, mv2, "triangle");
    ASSERT_EQ(t.toString(), "triangle\n0 3\n4 0\n0 0");
}

TEST(Triangle, Array)
{
    double u[2] = {0, 3};
    double w[2] = {4, 0};
    double v[2] = {0, 0};

    double u1[2] = {0, -3};
    double w1[2] = {4, 0};
    double v1[2] = {0, 0};

    double u2[2] = {0, 3};
    double w2[2] = {-4, 0};
    double v2[2] = {0, 0};

    double u3[2] = {0, -3};
    double w3[2] = {-4, 0};
    double v3[2] = {0, 0};

    int dim = 2;
    
    MathVector mv(dim, u), mv1(dim, w), mv2(dim, v);
    MathVector mv3(dim, u1), mv4(dim, w1), mv5(dim, v1);
    MathVector mv6(dim, u2), mv7(dim, w2), mv8(dim, v2);
    MathVector mv9(dim, u3), mv10(dim, w3), mv11(dim, v3);
    
    // Use here to test default constructor.
    Triangle z;
    Triangle *t = new Triangle[4];
    t[0].perimeter(); // we will come back later to see the nullptr issue.
    ASSERT_NEAR(0.0, t[0].perimeter(), 0.001);

    if(t){
        delete [] t;
    }
    t = nullptr;
}

TEST(Triangle, Area)
{
    double u[2] = {0, 3};
    double w[2] = {4, 0};
    double v[2] = {0, 0};
    int dim = 2;
    MathVector mv(dim, u), mv1(dim, w), mv2(dim, v);
    Triangle t(mv, mv1, mv2);
    ASSERT_NEAR(6, t.area(), 0.001);
}