#pragma once
#include <functor_sort.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(testsort, testFunctor)
{
    Functor_Sort obj;
    char actual[50] = "a/.f,dce;b";
    char expected[50] = "abcdef";
    obj(actual);
    for (int i = static_cast<int>(strlen(expected)-1); i < 50; i++)
    {
        actual[i] = '\0';
        expected[i] = '\0';
    }

    EXPECT_EQ(expected, actual);
}
TEST(testsortwithnoneed, testFunctor)
{
    Functor_Sort obj;
    char actual[7] = "abcdef";
    char expected[7] = "abcdef";
    obj(actual);

    EXPECT_EQ(expected, actual);
}
TEST(testsortwithoutjunk, testFunctor)
{
    Functor_Sort obj;
    char actual[7] = "bdefca";
    char expected[7] = "abcdef";
    obj(actual);

    EXPECT_EQ(expected, actual);
}
TEST(testsortempty, testFunctor)
{
    Functor_Sort obj;
    char actual[1] = "";
    char expected[1] = "";
    obj(actual);

    EXPECT_EQ(expected, actual);
}


