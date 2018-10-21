#pragma once
#include <iostream>


class Pal{
private:
    std::string str;
public:
    Pal(std::string const &s);
    bool operator()();
};
