#include "h8.h"

H8::H8(){}

std::vector<int> H8::operator()(const std::vector<int> &v){
    std::vector<int> m_v;
        for(auto& i : v){
            if(i != 8){
                m_v.push_back(i);
            }
        }
    return m_v;
}

