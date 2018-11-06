#include "ForSort.h"

/*
 *Program sort letters, which inputs from argv[];
*/

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
    std::cout << std::endl;
}


