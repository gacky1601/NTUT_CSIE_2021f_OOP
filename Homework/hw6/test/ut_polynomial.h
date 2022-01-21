#include "../src/polynomial.h"

class PolynomialTest : public ::testing::Test {
protected:
    const double DELTA = 0.001;
};

TEST_F(PolynomialTest, ConstructorTest) {
    Polynomial p1(vector<Term> {Term(-3, 2), Term(3, 0), Term(6, 3) }, 3);
    EXPECT_EQ(p1.term(0).coefficient(), 3);
    EXPECT_EQ(p1.term(1).coefficient(), 0);
    EXPECT_EQ(p1.term(2).coefficient(), -3);
    EXPECT_EQ(p1.term(3).coefficient(), 6);
    EXPECT_EQ(p1.degree(), 3);
    //Exception of duplicate terms
    EXPECT_THROW(Polynomial (vector<Term>{Term(5, 2), Term(2, 0), Term(3, 0)}, 2), string);
}
TEST_F(PolynomialTest, TermTest) {
    Polynomial p1(vector<Term> {Term(-3, 2), Term(3, 0), Term(6, 3) }, 3);
    EXPECT_EQ(p1.term(4), Term(0,4));
    EXPECT_EQ(p1.term(1), Term(0,1));
    EXPECT_EQ(p1.term(2), Term(-3,2));
    EXPECT_EQ(p1.term(3),Term( 6,3));
}
TEST_F(PolynomialTest, OperatorTest) {
    Polynomial p1(vector<Term> {Term(-3, 2), Term(3, 0), Term(6, 3) }, 3);
    Polynomial p2(vector<Term> { Term(10, 3), Term(4, 1), Term(6, 0)}, 3); 
    Polynomial p4(vector<Term> {Term(4, 1), Term(1, 0)}, 1);
    Polynomial p5(vector<Term> {Term(6, 1), Term(1, 0)}, 1);
    Term t1(6, 2);
    EXPECT_EQ((p1 + p2).degree(), 3);
    EXPECT_EQ((p1 + p2).term(3).coefficient(), 16);
    EXPECT_EQ((p1 + p2).term(2).coefficient(), -3);
    EXPECT_EQ((p1 + p2).term(1).coefficient(), 4);
    EXPECT_EQ((p1 + p2).term(0).coefficient(), 9);
    EXPECT_EQ((p4 * t1).degree(), 3);
    EXPECT_EQ((p4 * t1).term(3).coefficient(), 24);
    EXPECT_EQ((p4 * t1).term(2).coefficient(), 6);
    EXPECT_EQ((p4 * t1).term(1).coefficient(), 0);
    EXPECT_EQ((p4 * t1).term(0).coefficient(), 0);
    EXPECT_EQ((p4 * p5).degree(), 2);
    EXPECT_EQ((p4 * p5).term(2).coefficient(), 24);
    EXPECT_EQ((p4 * p5).term(1).coefficient(), 10);
    EXPECT_EQ((p4 * p5).term(0).coefficient(), 1);
}