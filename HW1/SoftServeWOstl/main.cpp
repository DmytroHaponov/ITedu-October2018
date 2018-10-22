#include "mergesort.h"

int main(){
    std::string* s = new std::string[81];
    s[0] = "Vasya ";
    s[1] = "Petya ";
    s[2] = "Katya ";
    s[3] = "Alex ";

    StringSort S;

    S.add(s);
    S.mergeSort(0, 80);
    S.merge(0, 40, 80);
    S.print();

    return 0;
}
