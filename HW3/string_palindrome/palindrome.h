#ifndef PALINDROME_H
#define PALINDROME_H
#include<string>
#include <ctype.h>
#include <algorithm>
#include <regex>
#include <gtest/gtest.h>


class Palindrome{
public:
    Palindrome();
    int operator()();
    bool tooper();
    bool singleSymbol();
    bool engSymbol();
    bool punctuationMarks();
    bool noneSympol();
private:
    std::string word;
};

class Palindrome_Test :public::testing::Test{
public:
    Palindrome t;
};

#endif // PALINDROME_H
