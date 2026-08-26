#include <climits>

#include <stdexcept>

#include <gtest/gtest.h>

#include <libmath.hpp>


TEST(AdditionTest, CorrectResult)
{
    EXPECT_EQ(libmath::addition(2, 3), 5);
}

TEST(AdditionTest, NegativeNumbers)
{
    EXPECT_EQ(libmath::addition(-2, -3), -5);
}

TEST(AdditionTest, Zero)
{
    EXPECT_EQ(libmath::addition(10, 0), 10);
}

TEST(AdditionTest, MaxIntOverflow)
{
    EXPECT_THROW(
        libmath::addition(INT_MAX, 1),
        std::overflow_error
    );
}

TEST(AdditionTest, MinIntOverflow)
{
    EXPECT_THROW(
        libmath::addition(INT_MIN, -1),
        std::overflow_error
    );
}


TEST(SubtractionTest, CorrectResult)
{
    EXPECT_EQ(libmath::subtraction(10, 3), 7);
}

TEST(SubtractionTest, NegativeNumbers)
{
    EXPECT_EQ(libmath::subtraction(-10, -3), -7);
}

TEST(SubtractionTest, Zero)
{
    EXPECT_EQ(libmath::subtraction(10, 0), 10);
}

TEST(SubtractionTest, MaxIntOverflow)
{
    EXPECT_THROW(
        libmath::subtraction(INT_MAX, -1),
        std::overflow_error
    );
}

TEST(SubtractionTest, MinIntOverflow)
{
    EXPECT_THROW(
        libmath::subtraction(INT_MIN, 1),
        std::overflow_error
    );
}


TEST(MultiplicationTest, CorrectResult)
{
    EXPECT_EQ(libmath::multiplication(5, 4), 20);
}

TEST(MultiplicationTest, NegativeNumbers)
{
    EXPECT_EQ(libmath::multiplication(-5, 4), -20);
}

TEST(MultiplicationTest, Zero)
{
    EXPECT_EQ(libmath::multiplication(100, 0), 0);
}

TEST(MultiplicationTest, MaxIntOverflow)
{
    EXPECT_THROW(
        libmath::multiplication(INT_MAX, 2),
        std::overflow_error
    );
}

TEST(MultiplicationTest, MinIntOverflow)
{
    EXPECT_THROW(
        libmath::multiplication(INT_MIN, 2),
        std::overflow_error
    );
}


TEST(DivisionTest, CorrectResult)
{
    EXPECT_EQ(libmath::division(10, 2), 5);
}

TEST(DivisionTest, NegativeNumbers)
{
    EXPECT_EQ(libmath::division(-10, 2), -5);
}

TEST(DivisionTest, ZeroNumerator)
{
    EXPECT_EQ(libmath::division(0, 10), 0);
}

TEST(DivisionTest, DivisionByZero)
{
    EXPECT_THROW(
        libmath::division(10, 0),
        std::domain_error
    );
}

TEST(DivisionTest, MinIntDividedByMinusOne)
{
    EXPECT_THROW(
        libmath::division(INT_MIN, -1),
        std::overflow_error
    );
}


TEST(PowerTest, CorrectResult)
{
    EXPECT_EQ(libmath::power(2, 3), 8);
}

TEST(PowerTest, ZeroExponent)
{
    EXPECT_EQ(libmath::power(10, 0), 1);
}

TEST(PowerTest, NegativeBase)
{
    EXPECT_EQ(libmath::power(-2, 3), -8);
}

TEST(PowerTest, NegativeExponent)
{
    EXPECT_THROW(
        libmath::power(2, -1),
        std::domain_error
    );
}

TEST(PowerTest, Overflow)
{
    EXPECT_THROW(
        libmath::power(2, 31),
        std::overflow_error
    );
}


TEST(FactorialTest, CorrectResult)
{
    EXPECT_EQ(libmath::factorial(5), 120);
}

TEST(FactorialTest, Zero)
{
    EXPECT_EQ(libmath::factorial(0), 1);
}

TEST(FactorialTest, One)
{
    EXPECT_EQ(libmath::factorial(1), 1);
}

TEST(FactorialTest, NegativeNumber)
{
    EXPECT_THROW(
        libmath::factorial(-1),
        std::domain_error
    );
}

TEST(FactorialTest, Overflow)
{
    EXPECT_THROW(
        libmath::factorial(13),
        std::overflow_error
    );
}