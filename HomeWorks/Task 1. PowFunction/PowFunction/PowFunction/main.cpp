#include <iostream>
#include "gtest/gtest.h"

#include "functions.h"

int main()
{
    std::cout << my_pow(2, 2) << std::endl;

    std::cout << my_pow(3, 3) << std::endl;

    std::cout << my_pow(0, 3) << std::endl;

    std::cout << my_pow(3, 0) << std::endl;

    std::cout << my_pow(4, -2) << std::endl;

    return 0;
}
