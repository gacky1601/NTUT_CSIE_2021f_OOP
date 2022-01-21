#include <gtest/gtest.h>

#include "../src/polynomial.h"

class PolynomialTest : public ::testing::Test
{
protected:
    Polynomial p1, p2;

    void SetUp() override
    {
        p1 = Polynomial({Term(3, 0), Term(6, 3), Term(-3, 2)}, 3);
        p2 = Polynomial({Term(2, 1), Term(1, 0)}, 1);
    }
};

TEST_F(PolynomialTest, Constructor)
{
    Polynomial p({Term(5, 1), Term(2, 0)}, 1);
    ASSERT_EQ(Term(2, 0), p.term(0));
    ASSERT_EQ(Term(5, 1), p.term(1));
}

TEST_F(PolynomialTest, ConstructorDuplicateTerms)
{
    ASSERT_THROW(Polynomial({Term(2, 0), Term(2, 0)}, 0), std::string);
}

TEST_F(PolynomialTest, TermLowerThanDegree)
{
    Polynomial p({Term(3, 0), Term(6, 3), Term(-3, 2)}, 3);
    ASSERT_EQ(Term(3, 0), p.term(0));
    ASSERT_EQ(Term(0, 1), p.term(1));
    ASSERT_EQ(Term(-3, 2), p.term(2));
    ASSERT_EQ(Term(6, 3), p.term(3));
}

TEST_F(PolynomialTest, OperatorAddition)
{
    Polynomial p = p1 + p2;
    ASSERT_EQ(Term(4, 0), p.term(0));
    ASSERT_EQ(Term(2, 1), p.term(1));
    ASSERT_EQ(Term(-3, 2), p.term(2));
    ASSERT_EQ(Term(6, 3), p.term(3));
}

TEST_F(PolynomialTest, OperatorMultipleByTerm)
{
    Polynomial p = p1 * Term(2, 1);
    ASSERT_EQ(Term(0, 0), p.term(0));
    ASSERT_EQ(Term(6, 1), p.term(1));
    ASSERT_EQ(Term(0, 2), p.term(2));
    ASSERT_EQ(Term(-6, 3), p.term(3));
    ASSERT_EQ(Term(12, 4), p.term(4));
}

TEST_F(PolynomialTest, OperatorMultipleByPoly)
{
    Polynomial p = p1 * p2;
    ASSERT_EQ(Term(3, 0), p.term(0));
    ASSERT_EQ(Term(6, 1), p.term(1));
    ASSERT_EQ(Term(-3, 2), p.term(2));
    ASSERT_EQ(Term(0, 3), p.term(3));
    ASSERT_EQ(Term(12, 4), p.term(4));
}