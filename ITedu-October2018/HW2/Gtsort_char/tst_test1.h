#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "myfunctor.h"

using namespace testing;

TEST(After_sort_arr_equally_arr2, Test1)
{
    const int size_arr=5;
    char arr[size_arr]={'d','c','o','a','s'};
    char arr2[size_arr]={'a','c','d','o','s'};
    MyFunctor fy;
    fy(arr,size_arr);
    for(int i=0;i<size_arr;i++)
    {
        EXPECT_EQ(arr2[i], arr[i]);
    }
    //ASSERT_THAT(0, Eq(0));
}

TEST(cin_arr, Test2)
{
    const int size_arr=5;
    char arr[size_arr];
    for(int i=0;i<size_arr;i++)
    {
    std::cin>>arr[i];
    }
    char arr2[size_arr]={'a','c','d','o','s'};
    MyFunctor fy;
    fy(arr,size_arr);
    for(int i=0;i<size_arr;i++)
    {
        EXPECT_EQ(arr2[i], arr[i]);
    }
    //ASSERT_THAT(0, Eq(0));
}
TEST(if_arr_emrty, Test2)
{
    const int size_arr=0;
    char arr[size_arr];
    char arr1[size_arr];
    MyFunctor fy;
    fy(arr,size_arr);
    EXPECT_THAT(arr1, Eq(arr));
}
