#ifndef NAMESSORTWOSTL_H
#define NAMESSORTWOSTL_H
#include <iostream>
#include <fstream>
#include <string>

class NamesSortWoSTL{
private:
    static int const size = 5000;
    static const int len = 50000;
    char *ascii = new char[len];
    std::string names[size];
    std::string temp;

public:
    NamesSortWoSTL();
    void AddToFile();
    std::string ReadFromFile();
    char WriteToArray();
    ~NamesSortWoSTL();
    void Sort();
    void Print();
    std::size_t GetWeight();
};

#endif // NAMESSORTWOSTL_H
