#ifndef FUNCTORSORTCHAR_H
#define FUNCTORSORTCHAR_H

#include <iostream>
#include <algorithm>
#include <deque>
#include <string.h>

class ForSort{
private:
    std::deque<char> str;
public:
    ForSort();
    void insert(const char *ch);
    ~ForSort();
    std::deque<char> operator()();
    void print();
};

ForSort::ForSort(){}

void ForSort::insert(const char *ch){
    for(size_t i = 0; i < strlen(ch); i++){
        if ((ch[i] > 64 && ch[i] < 91) || (ch[i] > 96 && ch[i] < 123)){
        str.push_back(ch[i]);
        }
    }
}

ForSort::~ForSort(){
    str.clear();
}

std::deque<char> ForSort::operator()(){
    std::stable_sort(str.begin(),str.end());
    return str;
}

void ForSort::print(){
    for(const auto& i :str){
        std::cout << i;
    }
}


#endif // FUNCTORSORTCHAR_H
