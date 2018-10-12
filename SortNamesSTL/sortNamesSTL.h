#ifndef SORTNAMESSTL_H
#define SORTNAMESSTL_H
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>

class SortNamesSTL{
private:
    std::deque<std::string> names;
    std::set<std::string> MySet;
public:
    SortNamesSTL();
    void WriteToFile();
    void ReadFromFile();
    void SortDeque();
    void GetSet();
    void PrintDeque();
    void PrintSet();
    ~SortNamesSTL();
};



#endif // SORTNAMESSTL_H
