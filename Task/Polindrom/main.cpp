#include <iostream>
#include <string>
#include <algorithm>

bool isPolindrome(const std::string f_string)
{
    std::string revers{f_string};
    std::reverse(revers.begin(),revers.end());
    //std::cout << revers << std::endl;
    return revers == f_string;
}

int main()
{
    std::string temp_string{" Hello olleH "};
    std::cout << temp_string << isPolindrome(temp_string) << std::endl;
    //isPolindrome(temp_string);
    return 0;
}