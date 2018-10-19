#ifndef FORSORT_H
#define FORSORT_H
#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <string.h>

class ForSort{
private:
    std::deque<char> str;
public:
    ForSort(const char *ch);
    ~ForSort();
    std::deque<char> operator()();
    void print();
};

#endif // FORSORT_H
