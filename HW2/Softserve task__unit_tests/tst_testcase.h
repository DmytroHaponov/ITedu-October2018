#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "sortmodule.h"

using namespace testing;

TEST(TestCaseSortWoSTL, SetTest1){
    add(names1);
    add(names2);
    mergeSort(0,80,names1);
    merge(0,40,80,names1);
    mergeSort(0,80,names2);
    merge(0,40,80,names2);
    EXPECT_EQ(*names1,*names2);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestCaseSortWoSTLNullString, SetTest2){
    add(names1);
    mergeSort(0,80,names1);
    merge(0,40,80,names1);
    mergeSort(0,80,names3);
    merge(0,40,80,names3);
    EXPECT_NE(*names1,*names3);
    ASSERT_THAT(0, Eq(0));
    delete[]names1;
    delete[]names2;
    delete[]names3;
    delete[]tmp;
}

TEST(TestCaseSortWithSTL, SetTest3){
    addDeque(Names1);
    addDeque(Names2);
    SortDeque(Names1);
    SortDeque(Names2);
    EXPECT_EQ(Names1,Names2);
    ASSERT_THAT(0, Eq(0));
    Names1.clear();
    Names2.clear();
}

TEST(TestCaseSortWithSTLNullDeque, SetTest4){
    addDeque(Names1);
    SortDeque(Names1);
    SortDeque(Names3);
    EXPECT_NE(Names1, Names3);
    ASSERT_THAT(0, Eq(0));
    Names1.clear();
    Names3.clear();
}
