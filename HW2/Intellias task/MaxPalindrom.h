#ifndef MAXPALINDROM_H
#define MAXPALINDROM_H
#include <iostream>
#include <string>
#include <sstream>

class MaxPalindrom{
private:
    int mult;
    int max;
    std::string smult;
public:
MaxPalindrom();
void Print(){
    std::cout << "Biggest palindron is: " << max << std::endl;
}
};

template<typename T>
std::string toString(T val);
template<typename T>
T fromString(const std::string& s);



#endif // MAXPALINDROM_H
