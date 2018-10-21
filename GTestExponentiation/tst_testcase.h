#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "functorexponentiation.h"
using namespace testing;


TEST(base_to_pow_1, testCase1){
    FunctorExponent f(5,1);
    EXPECT_EQ(f(),5);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_to_pow_0, testCase2){
    FunctorExponent f(5,0);
    EXPECT_EQ(f(),1);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_null_to_pow_1, testCase3){
    FunctorExponent f(0,1);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_less_null_to_pow_1, testCase4){
    FunctorExponent f(-1,1);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_null_to_pow_null, testCase5){
    FunctorExponent f(0,0);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_less_null_to_pow_less_null, testCase6){
    FunctorExponent f(-1,-1);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_to_pow_less_null, testCase7){
    FunctorExponent f(1,-1);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_less_null_to_pow_null, testCase8){
    FunctorExponent f(-1,0);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_null_to_pow_less_null, testCase9){
    FunctorExponent f(0,-1);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
TEST(base_null_to_pow_biger_null, testCase10){
    FunctorExponent f(0,1);
    EXPECT_EQ(f(),0);
    ASSERT_THAT(0, Eq(0));
}
