#ifndef FUNCTORSTRINGPALINDROM_H
#define FUNCTORSTRINGPALINDROM_H

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

Pal::Pal(){}

void Pal::copy(const std::string &s){
    CopyStr = s;
}

bool::Pal::operator()(){
    int counter = 0;

    for(unsigned long i = 0; i < CopyStr.length(); i++){
         CopyStr[i] = tolower(CopyStr[i]);
    }

    for(unsigned long i = 0; i < CopyStr.length()/2; i++){
        if(CopyStr[i] == CopyStr[CopyStr.length()-1-i]
           && CopyStr[i] > 64 && CopyStr[i] < 123){
             counter++;
        }
    }

    if(counter == CopyStr.length()/2 && CopyStr.length() > 2){
        return true;
    }
    else{
        return false;
    }
}



#endif // FUNCTORSTRINGPALINDROM_H
