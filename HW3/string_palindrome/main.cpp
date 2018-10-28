#include "tst_test_pal.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
//    std::string str;
//    //std::string newstr;
//    std::cout << "INput string: ";
//    getline(std::cin, str);

//    Is_Palindrome obj;
//    std::cout << obj (str) << " ";

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
