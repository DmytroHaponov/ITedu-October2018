#ifndef POLINDROM_H
#define POLINDROM_H
#include <iostream>
#include <algorithm>
#include <locale>

class Polindrom
{
public:
    std::string operator()(std::string P_str1);
    std::string deleteSymbol(std::string P_str2);
    std::string letter_case_changes(std::string P_str2);
};

#endif // POLINDROM_H
