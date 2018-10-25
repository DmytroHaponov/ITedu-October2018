#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <sorting_module.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace testing;

TEST(SortingTest, SortingStringsByAsc)
{
    Sorting_module sorting;

    std::vector<std::string> v1; //vector, sorted with self realized selection sort by ascending order
    std::vector<std::string> v2; //vector, sorted with sort algorithm

    v1.push_back("PHQGHUMEAY");
    v1.push_back("LNLFDXFIRC");
    v1.push_back("VSCXGGBWKF");
    v1.push_back("NQDUXWFNFO");
    v1.push_back("ZVSRTKJPRE");

    v2.push_back("PHQGHUMEAY");
    v2.push_back("LNLFDXFIRC");
    v2.push_back("VSCXGGBWKF");
    v2.push_back("NQDUXWFNFO");
    v2.push_back("ZVSRTKJPRE");

    sorting.selection_sort(v1);
    sort(v2.begin(),v2.end());

    EXPECT_EQ(v2,v1);
}

TEST(SortingTest, SortingStringsWithNumbers)
{
    Sorting_module sorting;

    std::vector<std::string> v1; //vector, sorted with self realized selection sort by ascending order
    std::vector<std::string> v2; //vector, sorted with sort algorithm

    v1.push_back("PHQ485MEAY");
    v1.push_back("593FDXFIRC");
    v1.push_back("193XGGBWKF");
    v1.push_back("5937XWFNFO");
    v1.push_back("ZVSRTKJP49");

    v2.push_back("PHQ485MEAY");
    v2.push_back("593FDXFIRC");
    v2.push_back("193XGGBWKF");
    v2.push_back("5937XWFNFO");
    v2.push_back("ZVSRTKJP49");

    sorting.selection_sort(v1);
    sort(v2.begin(),v2.end());

    EXPECT_EQ(v2,v1);
}

TEST(SortingTest, SortingEmptyStrings)
{
    Sorting_module sorting;

    std::vector<std::string> v1; //vector, sorted with self realized selection sort by ascending order
    std::vector<std::string> v2; //vector, sorted with sort algorithm

    v1.push_back("");
    v1.push_back("");
    v1.push_back("");
    v1.push_back("");
    v1.push_back("");

    v2.push_back("");
    v2.push_back("");
    v2.push_back("");
    v2.push_back("");
    v2.push_back("");

    sorting.selection_sort(v1);
    sort(v2.begin(),v2.end());

    EXPECT_EQ(v2,v1);
}

TEST(SortingTest, SortingEmptyVectors)
{
    Sorting_module sorting;

    std::vector<std::string> v1; //vector, sorted with self realized selection sort by ascending order
    std::vector<std::string> v2; //vector, sorted with sort algorithm

    sorting.selection_sort(v1);
    sort(v2.begin(),v2.end());

    ASSERT_EQ(v2,v1);
}
