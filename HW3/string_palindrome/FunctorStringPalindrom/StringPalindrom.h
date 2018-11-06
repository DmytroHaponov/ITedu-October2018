#pragma once

#include <iostream>
#include <string.h>
#include <ctype.h>

class Pal{
private:
    std::string CopyStr;
public:
    Pal();
    void copy(std::string const &s);
    bool operator()();
};
