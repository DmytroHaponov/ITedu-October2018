#pragma once

#include <gtest/gtest.h>

#include "list.h"

TEST(ListTest, GetSizeTest)
{
    List list;

    EXPECT_EQ(list.GetSize(), 0);
}

TEST(ListTest, AddTest)
{
    List list;

    EXPECT_EQ(list.GetSize(), 0);

    list.Add(1);
    list.Add(1);
    list.Add(1);

    EXPECT_EQ(list.GetSize(), 3);
}

TEST(ListTest, ClearTest)
{
    List list;

    EXPECT_EQ(list.GetSize(), 0);

    list.Add(1);

    EXPECT_EQ(list.GetSize(), 1);

    list.Clear();

    EXPECT_EQ(list.GetSize(), 0);
}

TEST(ListTest, GenerateListTest)
{
    List list;

    EXPECT_EQ(list.GetSize(), 0);

    list.GenerateList(5);

    EXPECT_EQ(list.GetSize(), 5);
}
