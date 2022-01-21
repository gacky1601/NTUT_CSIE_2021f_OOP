#include "../src/polygon.h"
#include "../src/shape.h"

class PolygonTest : public::testing::Test {
protected:
    Polygon p4; //p3;
    Polygon p5;
    Shape *p;
    Factory f;
    void SetUp() override {
        int dim = 2;    
        double x1[2] = {1, 0};
        double x2[2] = {1, 3};
        double x3[2] = {4, 3};
        double x4[2] = {4, 0};
        MathVector m1(dim, x1);
        MathVector m2(dim, x2);
        MathVector m3(dim, x3);
        MathVector m4(dim, x4);
        MathVector v[4] = {m1, m3, m2, m4}; // v[4] -> unknown
                                            // v[0](m1);
        p4 = f.createPolygon(4, v);

        double a1[2] = {0, 0};
        double a2[2] = {2, 0};
        double a3[2] = {2, 4};
        double a4[2] = {2, 5};
        double a5[2] = {0, 4};
        MathVector m21(dim, a1);
        MathVector m22(dim, a2);
        MathVector m23(dim, a3);
        MathVector m24(dim, a4);
        MathVector m25(dim, a5);
        MathVector v2[5] = {m21, m24, m25, m23, m22};
        p5 = createPolygonSA(5, v2);
        //MathVector u[3] = {m1, m2, m3};
        //p3 = Polygon(3, u);
        // Shape shape; -> illegal.
        // Shape* shape = new Shape(); -> illegal.
        //*p = ; Pointer have not pointed anything yet. 
        // p = &Polygon::createPolygon(5, v2); -> illegal.
        p = &p5;
        
    }
};

TEST_F(PolygonTest, shapePointer) {
    ASSERT_NEAR(p->perimeter(), (double)(11+std::sqrt(5)), 0.001);
}

/*TEST_F(PolygonTest, centroidTest){
    ASSERT_NEAR(p4.getCentroid().at(0), 2.5, 0.01);
    ASSERT_NEAR(p4.getCentroid().at(1), 1.5, 0.01);
}*/

TEST_F(PolygonTest, perimeterTest){
    ASSERT_NEAR(p4.perimeter(), 12.0, 0.001);
}

TEST_F(PolygonTest, areaTest){
    ASSERT_NEAR(p4.area(), 9.0, 0.001);
}

TEST_F(PolygonTest, perimeterTestP5){
    ASSERT_NEAR(p5.perimeter(), (double)(11+std::sqrt(5)), 0.001);
}

TEST_F(PolygonTest, areaTestP5){
    ASSERT_NEAR(p5.area(), 9.0, 0.001);
}
/*
TEST_F(PolygonTest, perimeterCompare){
    ASSERT_FALSE(p5 < p3);
}
*/
TEST(StdSort, simpleSort){ // ascending
    int a[5] = {1, 3, 2, 6, 5};
    std::vector<int> b;
    for(int i = 0; i < 5; i++){
        b.push_back(a[i]);
    }
    std::sort(b.begin(), b.begin() + b.size()); // aka b.end()
    std::sort(a, a + 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(b[4], 6);
}

bool greaterThan(int a, int b){
    return (a > b);
}

TEST(StdSort, simpleSort2){ // descending
    int a[5] = {1, 3, 2, 6, 5};
    std::sort(a, a + 5, greaterThan);
    ASSERT_EQ(a[0], 6);
}

bool distanceToNine(int a, int b){
    return (9 - a) > (9 -b);
}

TEST(StdSort, simpleSort3){ // descending
    int a[5] = {1, 3, 2, 6, 5};
    std::sort(a, a + 5, distanceToNine);
    ASSERT_EQ(a[0], 1);
}

