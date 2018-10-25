#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <sortmodule.h>
using namespace testing;

TEST(tetsSort1, Words)
{
    std::string wordsNosort[5] = {"Maxim","Andriy","Vitaliy","Ivan","Dmytro"};
    std::string wordsort[5] = {"Andriy","Dmytro","Ivan","Maxim","Vitaliy"};
    sortModule sort;
    sort.quickSort(wordsNosort,0,4);
    EXPECT_EQ(*wordsort,*wordsNosort);

}

TEST(testSort2,ArrWhithoutword){
    std::string wordsNosort[5] = {"Maxim","","Vitaliy","Ivan",""};
    std::string wordsort[5] = {"","","Ivan","Maxim","Vitaliy"};
    sortModule sort;
    sort.quickSort(wordsNosort,0,4);
    EXPECT_EQ(*wordsort,*wordsNosort);
}
