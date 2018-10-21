#include <functorerasevalue8inmap.h>
#include <map>
#include <iostream>

H8::H8(){

}
std::map<int,int> H8::operator()(const std::map<int,int> &init){
    std::map<int,int> m;

    for(const auto& i : init){
        if(i.second != 8){
           m.insert(i);
        }
    }
    return m;
}
