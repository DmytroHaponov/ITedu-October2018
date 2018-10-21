#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "rails.h"

using namespace testing;

TEST(control_testcase, control_testset){
    Rails rail(1,7,3);
    rail.pushRails(1,1,2);
    rail.pushRails(1,2,4);
    rail.pushRails(1,3,5);
    rail.searchFree();
    EXPECT_EQ(rail.GetCounter(), 2);
    ASSERT_THAT(0, Eq(0));
}

TEST(row_less_0, testset1){
    Rails rail(0,2,1);
    rail.pushRails(0,1,2);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(colunmns_bigger_10_9, testset2){
    Rails rail(1,1000000000,1);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(rails_less_0, testset3){
    Rails rail(1,1,-1);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(rails_more_1000, testset4){
    Rails rail(1,1,1001);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(row_push_less_1, testset5){
    Rails rail(1,1,1);
    rail.pushRails(0,1,1);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(row_push_bigger_row, testset6){
    Rails rail(1,1,1);
    rail.pushRails(2,1,1);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(c1_less_1, testset7){
    Rails rail(1,1,1);
    rail.pushRails(1,0,1);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(c1_bigger_column, testset8){
    Rails rail(1,1,1);
    rail.pushRails(1,2,1);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(c2_bigger_column, testset9){
    Rails rail(1,1,1);
    rail.pushRails(1,1,2);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}
TEST(c2_less_1, testset10){
    Rails rail(1,1,1);
    rail.pushRails(1,1,0);
    rail.searchFree();
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}

TEST(colunmns_less_1, testset11){
    Rails rail(1,0,1);
    EXPECT_EQ(rail.GetCounter(), 0);
    ASSERT_THAT(0, Eq(0));
}
