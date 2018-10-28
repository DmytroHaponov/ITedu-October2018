#include <StringPalindrom.h>

/*
 * Program verifying text palindrome in string
*/

//copy of string//

    Pal::Pal(){}

//owerwrite in copy of string all letters to lower register
//and verify text palindrome//

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
