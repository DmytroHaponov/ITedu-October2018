#include "MaxPalindrom.h"


template <typename T>
std::string toString(T val){
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

template<typename T>
T fromString(const std::string& s){
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}

MaxPalindrom::MaxPalindrom(){

        for (int i = 100; i < 1000; i++){
            for (int j = 100; j < 1000; j++){
                mult = i*j;
                smult = toString(mult);
                int counter = 0;
                for (int k = 0; k < smult.length()/2; k++){
                    if(smult[k] == smult[smult.length()-1-k]){
                        counter++;
                    }
                    if(counter == 3 && max < mult){
                        max = mult;
                    }
                }
            }
        }
}


