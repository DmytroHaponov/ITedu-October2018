#include "tst_sorting_names_test.h"

#include <gtest/gtest.h>
#include "header.h"

int main(int argc, char *argv[])
{
    char name_of_file[] = "MyFile.txt";

//    int words_number = generate_file(name_of_file);
    int words_number = 20;

    char **names = new char*[words_number];
    for (int i = 0; i < words_number; i++)
    {
        names[i] = new char[10];
    }
    //char names[words_number][10];

    read_from_file (names, words_number, name_of_file);
    //std::cout << "hash = ";
    sort(names, words_number);
    std::cout << "//////////////sort//////////////////////" << std::endl << std::endl;
    for (int i = 0;i<words_number; i++)
    {
        std::cout << names[i] <<std::endl;
    }
    std::cout << "////////////////////////////////////" << std::endl << std::endl;
    write_in_file (names, words_number);
    std::cout << "hash = " << hash (names, words_number) << std::endl;
    for (int i = 0; i < words_number; i++)
    {
        delete [] names[i];
    }
    delete [] names;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

