#pragma once
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "is_palindrome.h"

using namespace testing;

TEST(TEST_PAL, TESTINGFUNCTOR)
{
    Is_Palindrome obj;
    std::string s = "ssdss";
    EXPECT_EQ(obj(s), 1);
}
TEST(TEST_PAL_SINGLE_LETTER, TESTINGFUNCTOR)
{
    Is_Palindrome obj;
    std::string s = "d";
    EXPECT_EQ(obj(s), 1);
}
TEST(TEST_PAL_WITH_JUNK, TESTINGFUNCTOR)
{
    Is_Palindrome obj;
    std::string s = "ss///ds//s";
    EXPECT_EQ(obj(s), 1);
}
TEST(TEST_NON_PAL_WITH_JUNK, TESTINGFUNCTOR)
{
    Is_Palindrome obj;
    std::string s = "ss///dM//s";
    EXPECT_EQ(obj(s), 0);
}
TEST(TEST_EMPTY_PAL, TESTINGFUNCTOR)
{
    Is_Palindrome obj;
    std::string s = "";
    EXPECT_EQ(obj(s), 0);
}
TEST(TEST_EMPTY_CAP, TESTINGFUNCTOR)
{
    Is_Palindrome obj;
    std::string s = "AaADAAA";
    EXPECT_EQ(obj(s), 1);
}
