#include "palindrome.h"

Palindrome::Palindrome()
{
    word = "abssba";
}

int Palindrome::operator()()
{
    return std::equal(word.begin(),word.end(),word.rbegin()) ? 1:0;
}

bool Palindrome::tooper()
{
    std::string symbols= "QWERTYUIOPASDFGHJKLZXCVBNM";
    std::string::iterator it;

    for(it = word.begin(); it!=word.end(); ++it){
       if(std::find(symbols.begin(),symbols.end(),*it)!=symbols.end()){
           return false;
       }
    }
    return true;
}

bool Palindrome::singleSymbol()
{
    if (word.size() == 1){
        return false;
    }
    else {
        return true;
    }
}

bool Palindrome::engSymbol()
{
    std::regex r("^[a-zA-Z]+$");
    return std::regex_match(word,r);
}

bool Palindrome::punctuationMarks()
{
    std::string marks= "~!@#$%^&*()_+}{[]}/*-+/ '<>?`";
    std::string::iterator it;

    for(it = word.begin(); it!=word.end(); ++it){
       if(std::find(marks.begin(),marks.end(),*it)!=marks.end()){
           return false;
       }
    }
    return true;
}

bool Palindrome::noneSympol()
{
    if(word == ""){
        return false;
    }
    else return true;
}


