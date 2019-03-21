#include <iostream>

#include "functions.h"

int main()
{
    std::string str = "abcba";

    if(is_palindrom(str))
    {
        std::cout << str << " is palindrom!" << std::endl;
    }
    else
    {
        std::cout << str << " is not palindrom!" << std::endl;
    }

    return 0;
}
