#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "polindrom.h"

using namespace testing;

TEST(deleteSymbol, test1)
{
    std::string text="%4txt&^%";
    Polindrom obj;
    text=obj.deleteSymbol(text);
    text=obj.letter_case_changes(text);
    std::string text1="txt";
    obj(text);
    EXPECT_EQ(text,text1);
    //ASSERT_THAT(0, Eq());
}
TEST(letter_case_changes, test2)
{
    std::string text="Txt";
    Polindrom obj;
    text=obj.deleteSymbol(text);
    text=obj.letter_case_changes(text);
    std::string text1="txt";
    obj(text);
    EXPECT_EQ(text,text1);
    //ASSERT_THAT(0, Eq());
}

TEST(if_is_polindrome, test3)
{
    std::string text="Txt";
    Polindrom obj;
    text=obj.deleteSymbol(text);
    text=obj.letter_case_changes(text);
    std::string text1="This text is polindrom";
    std::string text2=obj(text);
    EXPECT_EQ(text2,text1);
    //ASSERT_THAT(0, Eq());
}
