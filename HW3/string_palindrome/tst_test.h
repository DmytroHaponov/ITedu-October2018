#pragma once
#include <palindrome.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST_F(Palindrome_Test, noneSymbol){
    EXPECT_TRUE(t.noneSympol());
}
TEST_F(Palindrome_Test, singleSymbol)
{
    EXPECT_TRUE(t.singleSymbol());
}
TEST_F(Palindrome_Test,Punctuation_marks){
    EXPECT_TRUE(t.punctuationMarks());
}
TEST_F(Palindrome_Test,engSymbor){
     EXPECT_TRUE(t.engSymbol());
}
TEST_F(Palindrome_Test,tooper){
    EXPECT_TRUE(t.tooper());
}

TEST_F(Palindrome_Test,Palindrome){
    EXPECT_EQ(1,t());
}

