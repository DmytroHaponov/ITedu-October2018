#pragma once
#include "header.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;


//void read_from_file(char **names,int words_number,char filename[])
TEST(test_of_sort, testing_func)
{
    int words_number = 5000;
    char filename_actual[14] = "Actual.txt";
    char filename_expected[14] = "Expected.txt";
    char **actual = gen_2d_array(words_number);
    read_from_file(actual, words_number, filename_actual);
    sort(actual, words_number);

    char **expected = gen_2d_array(words_number);
    read_from_file(expected, words_number, filename_expected);
//    for (int i = 0; i < words_number; i++)
//    {
//        std::cout << actual[i] << std::endl;
//    }
//    std::cout << "///////////\n";
//    for (int i = 0; i < words_number; i++)
//    {
//        std::cout << expected[i] << std::endl;
//    }


    ASSERT_EQ(actual, expected);

    //ASSERT_THAT(0, Eq(0));


    for (int i = 0; i < words_number; i++)
    {
        delete [] actual[i];
    }
    delete [] actual;


    for (int i = 0; i < words_number; i++)
    {
        delete [] expected[i];
    }
    delete [] expected;
}

//TEST(DISABLE_test_of_file_read, testing_func)
//{
//    int words_number = 10;
//    char filename_actual[16] = "Actual_r.txt";
//    char **actual = gen_2d_array(words_number);
//    read_from_file(actual, words_number, filename_actual);

//    char **expected = gen_2d_array(words_number);
//    expected[0] = const_cast<char*>("Tom");
//    expected[1] = const_cast<char*>("Sam");
//    expected[2] = const_cast<char*>("Scraald");
//    expected[3] = const_cast<char*>("Eeren");
//    expected[4] = const_cast<char*>("Armin");
//    expected[5] = const_cast<char*>("Krista");
//    expected[6] = const_cast<char*>("Clare");
//    expected[7] = const_cast<char*>("Mikasa");
//    expected[8] = const_cast<char*>("Clark");
//    expected[9] = const_cast<char*>("Fred");



//    EXPECT_EQ(actual, expected);

//    //ASSERT_THAT(0, Eq(0));


//    for (int i = 0; i < words_number; i++)
//    {
//        delete [] actual[i];
//    }
//    delete [] actual;


//    for (int i = 0; i < words_number; i++)
//    {
//        delete [] expected[i];
//    }
//    delete [] expected;
//}
