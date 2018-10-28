#ifndef FORSORT_H
#define FORSORT_H

#include <iostream>
#include <algorithm>
#include <deque>
#include <string.h>


class ForSort{
private:
    std::deque<char> str;
public:
    ForSort();
    void insert(const char *ch);
    ~ForSort();
    std::deque<char> operator()();
    void print();
};

#endif // FORSORT_H
