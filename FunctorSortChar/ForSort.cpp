#include "ForSort.h"
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <string.h>


ForSort::ForSort(const char *ch){
    for(int i = 0; i < strlen(ch); i++){
        str.push_back(ch[i]);
    }
}

ForSort::~ForSort(){
    str.clear();
}

void ForSort::operator()(){
    std::stable_sort(str.begin(),str.end());
}

void ForSort::print(){
    std::copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout," "));
    std::cout << std::endl;
}


