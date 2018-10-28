#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "functorStringPalindrom.h"

using namespace testing;

TEST(TestPalindrom, SetTest1){
    std::string ss ="racecar";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestNonPalindrom, SetTest2){
    std::string ss ="raceca";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestNullString, SetTest3){
    std::string ss = "";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestSymbol, SetTest4){
    std::string ss = "....";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestBigLetter, SetTest5){
    std::string ss = "Rar";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestBigLetter, SetTest6){
    std::string ss = "raR";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestBigLetter2, SetTest7){
    std::string ss = "RaR";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestALLBigLetter, SetTest8){
    std::string ss = "RAR";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestSymbolWithPal, SetTest9){
    std::string ss = "/RAR/";
    Pal p;
    p.copy(ss);
    EXPECT_EQ(p(), 0);
    ASSERT_THAT(0, Eq(0));
}
