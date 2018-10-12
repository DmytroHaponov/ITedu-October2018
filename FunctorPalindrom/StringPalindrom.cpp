#include <StringPalindrom.h>
#include <iostream>
#include <string.h>


Pal::Pal(std::string const &s){
   str = s;
}
bool::Pal::operator()(){
    int counter = 0;
    for(int i = 0; i < str.length()/2; i++){
        if(str[i] == str[str.length()-1-i]){
             counter++;
        }
    }
    if(counter == str.length()/2){
        std::cout << "true\n";
        return true;
    }
    else{
        std::cout<<"false\n";
        return false;
    }
}
