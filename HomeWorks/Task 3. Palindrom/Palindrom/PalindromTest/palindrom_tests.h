#pragma once

#include <gtest/gtest.h>

#include "functions.h"

TEST(PalindromTest, PalindromTest_aba)
{
    ASSERT_TRUE(is_palindrom("aba"));
}

TEST(PalindromTest, PalindromTest_abac)
{
    ASSERT_FALSE(is_palindrom("abac"));
}

TEST(PalindromTest, PalindromTest_)
{
    ASSERT_TRUE(is_palindrom(""));
}

TEST(PalindromTest, PalindromTest_aAaa)
{
    ASSERT_FALSE(is_palindrom("aAaa"));
}

TEST(PalindromTest, PalindromTest_aAAa)
{
    ASSERT_TRUE(is_palindrom("aAAa"));
}
