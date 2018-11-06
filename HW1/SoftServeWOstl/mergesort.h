#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>

class StringSort{
private:
    int len = 81;
    std::string* names = new std::string[len];
    std::string* tmp = new std::string[len];
public:
    StringSort();
    void mergeSort(int low, int hight);
    void merge(int low, int mid, int hight);
    void print();
    ~StringSort();
    std::string add(const std::string* str);
};

#endif // MERGESORT_H
