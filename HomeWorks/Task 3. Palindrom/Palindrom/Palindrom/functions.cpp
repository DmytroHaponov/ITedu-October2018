#include "functions.h"

bool is_palindrom(std::string str)
{
    bool res = true;

    for(unsigned long i{0}; i < str.length() / 2; ++i)
    {
        if(str[i] != str[str.length() - i - 1])
        {
            res = false;
            break;
        }
    }

    return res;
}
