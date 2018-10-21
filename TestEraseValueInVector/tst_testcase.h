#pragma once
#include "h8.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(case_wo_8, SetTest1){
    H8 h8;
    std::vector<int> init = {1,2,3,9};
    std::vector<int> expec = {1,2,3,9};
    EXPECT_EQ(h8(init), h8(expec));
    ASSERT_THAT(0, Eq(0));
}

TEST(case_with_8, SetTest2){
    H8 h8;
    std::vector<int> init = {1,2,3,8,9};
    std::vector<int> expec = {1,2,3,9};
    EXPECT_EQ(h8(init), h8(expec));
    ASSERT_THAT(0, Eq(0));
}
TEST(case_null_vector, SetTest3){
    H8 h8;
    std::vector<int> init;
    std::vector<int> expec;
    EXPECT_EQ(h8(init), h8(expec));
    ASSERT_THAT(0, Eq(0));
}
