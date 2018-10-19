#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "functorsortchar.h"

using namespace testing;

TEST(TestCaseLetters, SetTest1){
    char *ch = new char[81];
    ch[0] = 'A';
    ch[1] = 'a';
    ch[2] = 'B';
    ch[3] = '\0';
    std::deque<char> expect = {'A', 'B', 'a'};
    ForSort st(ch);
    EXPECT_EQ(st(), expect);
    ASSERT_THAT(0, Eq(0));
}
TEST(TestCaseAllSymbols, SetTest2){
    char *ch = new char[81];
    ch[0] = 'A';
    ch[1] = 'a';
    ch[2] = 'B';
    ch[3] = '[';
    ch[4] = '.';
    ch[5] = '\0';
    std::deque<char> expect = {'A', 'B', 'a'};
    ForSort st(ch);
    EXPECT_EQ(st(), expect);
    ASSERT_THAT(0, Eq(0));
}
