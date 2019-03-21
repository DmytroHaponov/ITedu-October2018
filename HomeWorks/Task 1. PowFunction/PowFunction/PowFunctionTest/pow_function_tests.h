#pragma once

#include <gtest/gtest.h>

#include "../PowFunction/functions.h"

TEST(PowFunctionTest, PowInputsTest2_2)
{
    ASSERT_DOUBLE_EQ(4, my_pow(2, 2));
}

TEST(PowFunctionTest, PowInputsTest3_3)
{
    ASSERT_DOUBLE_EQ(27, my_pow(3, 3));
}

TEST(PowFunctionTest, PowInputsTest0_3)
{
    ASSERT_DOUBLE_EQ(0, my_pow(0, 3));
}

TEST(PowFunctionTest, PowInputsTest3_0)
{
    ASSERT_DOUBLE_EQ(1, my_pow(3, 0));
}

TEST(PowFunctionTest, PowInputsTest4_min2)
{
    ASSERT_DOUBLE_EQ(0.0625, my_pow(4, -2));
}
