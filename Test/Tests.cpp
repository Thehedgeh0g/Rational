//
// Created by flipd on 03.05.2024.
//
#include <gtest/gtest.h>
#include <sstream>
#include "../CRational.h"

bool AreEqual(double a, double b, double epsilon = 0.00001) {
    return std::abs(a - b) < epsilon;
}

TEST(CRationalTest, TestSuccessfulCreateEmpty)
{
    CRational rational;
    EXPECT_EQ(rational.GetNumerator(), 0);
    EXPECT_EQ(rational.GetDenominator(), 1);
}

TEST(CRationalTest, TestSuccessfulCreateWithInt)
{
    CRational rational(10);
    EXPECT_EQ(rational.GetNumerator(), 10);
    EXPECT_EQ(rational.GetDenominator(), 1);
}

TEST(CRationalTest, TestSuccessfulCreateWithNumAndDenum)
{
    CRational rational(10, 1);
    EXPECT_EQ(rational.GetNumerator(), 10);
    EXPECT_EQ(rational.GetDenominator(), 1);
}

TEST(CRationalTest, TestSuccessfulCreateWithNumAndDenumOfInt)
{
    CRational rational(10, 2);
    EXPECT_EQ(rational.GetNumerator(), 5);
    EXPECT_EQ(rational.GetDenominator(), 1);
}

TEST(CRationalTest, TestSuccessfulCreateWithNegNumAndPosDenum)
{
    CRational rational(-10, 1);
    EXPECT_EQ(rational.GetNumerator(), -10);
    EXPECT_EQ(rational.GetDenominator(), 1);
}

TEST(CRationalTest, TestSuccessfulCreateWithPosNumAndNegDenum)
{
    CRational rational(10, -1);
    EXPECT_EQ(rational.GetNumerator(), -10);
    EXPECT_EQ(rational.GetDenominator(), 1);
}

TEST(CRationalTest, TestCanNotCreateWithZeroDenum)
{
    EXPECT_THROW(
        {
            CRational rational(10, 0);
        },
        std::invalid_argument
    );
}

TEST(CRationalTest, TestSuccessfulToDoubleConvertation)
{
    CRational rational(3, 5);
    double expectingDouble = 0.6;
    EXPECT_TRUE(AreEqual(rational.ToDouble(), expectingDouble));
}

TEST(CRationalTest, TestSuccessfulConvertToMixed)
{
    CRational rational(7, 5);
    std::pair<int, CRational> expectingPair = {1, CRational(2, 5)};
    EXPECT_EQ(rational.ToCompoundFraction(), expectingPair);
}

TEST(CRationalTest, TestSuccessfulConvertIntToMixed)
{
    CRational rational(5, 5);
    std::pair<int, CRational> expectingPair = {1, CRational(0, 1)};
    EXPECT_EQ(rational.ToCompoundFraction(), expectingPair);
}

TEST(CRationalTest, TestSuccessfulConvertRatToMixed)
{
    CRational rational(2, 5);
    std::pair<int, CRational> expectingPair = {0, CRational(2, 5)};
    EXPECT_EQ(rational.ToCompoundFraction(), expectingPair);
}

TEST(CRationalTest, TestSuccessfulConvertRatToMixedWithZeroNum)
{
    CRational rational(0, 5);
    std::pair<int, CRational> expectingPair = {0, CRational(0, 1)};
    EXPECT_EQ(rational.ToCompoundFraction(), expectingPair);
}

TEST(CRationalTest, TestSuccessfulConvertToNegative)
{
    CRational rational(7, 5);
    CRational expectingRational(-7, 5);
    EXPECT_EQ(-rational, expectingRational);
}

TEST(CRationalTest, TestSuccessfulConvertToPositive)
{
    CRational rational(7, 5);
    CRational expectingRational(7, 5);
    EXPECT_EQ(+rational, expectingRational);
}

TEST(CRationalTest, TestSuccessfulSum)
{
    CRational rationalA(5, 5);
    CRational rationalB(2, 1);
    CRational expectingRational(3, 1);
    EXPECT_EQ(rationalA+rationalB, expectingRational);
}

TEST(CRationalTest, TestSuccessfulSumWithInt)
{
    CRational rationalA(5, 5);
    CRational expectingRational(3, 1);
    EXPECT_EQ(rationalA + 2, expectingRational);
}

TEST(CRationalTest, TestSuccessfulSubtraction)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 1);
    CRational expectingRational(-3, 5);
    EXPECT_EQ(rationalA-rationalB, expectingRational);
}

TEST(CRationalTest, TestSuccessfulSubtractionWithInt)
{
    CRational rationalA(7, 5);
    CRational expectingRational(-3, 5);
    EXPECT_EQ(rationalA-2, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarSum)
{
    CRational rationalA(5, 5);
    CRational rationalB(2, 1);
    rationalA+=rationalB;
    CRational expectingRational(3, 1);
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarSumWithInt)
{
    CRational rationalA(5, 5);
    rationalA+=2;
    CRational expectingRational(3, 1);
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarSubtraction)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    rationalA-=rationalB;
    CRational expectingRational(11, 15);
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarSubtractionWithInt)
{
    CRational rationalA(7, 5);
    rationalA-=2;
    CRational expectingRational(-3, 5);
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulMultiply)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(14, 15);
    EXPECT_EQ(rationalA*rationalB, expectingRational);
}

TEST(CRationalTest, TestSuccessfulMultiplyWithInt)
{
    CRational rationalA(7, 5);
    CRational expectingRational(14, 5);
    EXPECT_EQ(rationalA*2, expectingRational);
}

TEST(CRationalTest, TestSuccessfulDiv)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(21, 10);
    EXPECT_EQ(rationalA/rationalB, expectingRational);
}

TEST(CRationalTest, TestSuccessfulDivWithInt)
{
    CRational rationalA(7, 5);
    CRational expectingRational(7, 10);
    EXPECT_EQ(rationalA/2, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarMultiply)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(14, 15);
    rationalA*=rationalB;
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarMultiplyWithInt)
{
    CRational rationalA(7, 5);
    CRational expectingRational(14, 5);
    rationalA*=2;
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarDiv)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(21, 10);
    rationalA/=rationalB;
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulUnarDivWithInt)
{
    CRational rationalA(7, 5);
    CRational expectingRational(7, 10);
    rationalA/=2;
    EXPECT_EQ(rationalA, expectingRational);
}

TEST(CRationalTest, TestSuccessfulCompareEqual)
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);
    EXPECT_TRUE(rationalA == rationalB);
}

TEST(CRationalTest, TestCanNotCompareEqual)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 5);
    EXPECT_FALSE(rationalA == rationalB);
}

TEST(CRationalTest, TestSuccessfulCompareNotEqual)
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 5);
    EXPECT_TRUE(rationalA != rationalB);
}

TEST(CRationalTest, TestCanNotCompareNotEqual)
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);
    EXPECT_FALSE(rationalA != rationalB);
}

TEST(CRationalTest, TestSuccessfulCompareSmallerEqual)
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_TRUE(rationalA <= rationalB);
    EXPECT_TRUE(rationalC <= rationalB);
}

TEST(CRationalTest, TestCanNotCompareCompareSmallerEqual)
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_FALSE(rationalB <= rationalC);
}

TEST(CRationalTest, TestSuccessfulCompareSmaller)
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_TRUE(rationalC < rationalB);
}

TEST(CRationalTest, TestCanNotCompareCompareSmaller)
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_FALSE(rationalB < rationalC);
}

TEST(CRationalTest, TestSuccessfulCompareBiggerEqual)
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_TRUE(rationalA >= rationalB);
    EXPECT_TRUE(rationalB >= rationalC);
}

TEST(CRationalTest, TestCanNotCompareCompareBiigerEqual)
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_FALSE(rationalC >= rationalB);
}

TEST(CRationalTest, TestSuccessfulCompareBiiger)
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_TRUE(rationalB > rationalC);
}

TEST(CRationalTest, TestCanNotCompareCompareBiiger)
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);
    EXPECT_FALSE(rationalC > rationalB);
}

TEST(CRationalTest, TestSuccesfullCoutAndCin)
{
    CRational rationalB(7, 5);
    CRational rationalA;
    std::stringstream ss;
    ss << rationalB;
    ss >> rationalA;
    EXPECT_EQ(rationalA, rationalB);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}