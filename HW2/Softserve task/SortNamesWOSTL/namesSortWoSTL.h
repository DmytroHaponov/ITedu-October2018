#ifndef NAMESSORTWOSTL_H
#define NAMESSORTWOSTL_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>

class NamesSortWoSTL{
private:
    static const int size = 5000;
    static const int len = 50000;
    char *ascii = new char[len];
    std::string *names = new std::string[size];
    std::string temp;
    std::string *tmp = new std::string[size];

public:
    NamesSortWoSTL();
    void AddToFile();
    std::string ReadFromFile();
    char WriteToArray();
    ~NamesSortWoSTL();
    void mergeSort(int low, int hight);
    void merge(int low, int mid, int hight);
    void Print();
    int GetWeight();
};

#endif // NAMESSORTWOSTL_H
