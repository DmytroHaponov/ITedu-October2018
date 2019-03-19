#pragma once

#include <gtest/gtest.h>

#include "../HasVectorOdd/vector_functions.h"

TEST(HasVectorOddTest, FillVectorTest)
{
    std::vector<int> vect;

    fillVector(std::ref(vect), 7);

    EXPECT_EQ(vect.size(), 7);
}

TEST(HasVectorOddTest, HasVectorOddTest_Yes)
{
    std::vector<int> vect;

    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);

    EXPECT_TRUE(hasVectorOdd(std::ref(vect)));
}

TEST(HasVectorOddTest, HasVectorOddTest_No)
{
    std::vector<int> vect;

    vect.push_back(2);
    vect.push_back(4);
    vect.push_back(6);

    EXPECT_FALSE(hasVectorOdd(std::ref(vect)));
}
