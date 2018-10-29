#include"palindrome.h"
#include<string>

Palindrome::Palindrome()
{

}

bool Palindrome::IsPalindrome(const std::string &str)
{
    if(str.empty())
    {
        return false;
    }

    unsigned long long int i=0;
    unsigned long long int k=str.length()-1;

    while (i<k)
    {
        if(str[i]!=str[k])
        {
            return false;
        }
        i++;
        k--;
    }

    return true;
}
