#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <palindrome.h>
#include <string>

using namespace testing;

TEST(PalinTest, is_palin_true)
{
    //Expect true
    Palindrome pal;
    std::string str="losttsol";
    EXPECT_TRUE(pal.IsPalindrome(str));
}

TEST(PalinTest, is_palin_false)
{
    //Expect false
    Palindrome pal;
    std::string str="lostlost";
    EXPECT_FALSE(pal.IsPalindrome(str));
}

TEST(PalinTest, is_palin_empty)
{
    //Expect empty
    Palindrome pal;
    std::string str="";
    EXPECT_FALSE(pal.IsPalindrome(str));
}
