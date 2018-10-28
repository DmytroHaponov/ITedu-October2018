#include "tst_testsort.h"
#include "functor_sort.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    unsigned int lenght = 0;
    std::cout << argv[0] << '\n';
    if (strcmp(argv[1], "sort") == 0)
    {
    std::cout << "argc = " << argc << std::endl;
        for (int i = 2; i < argc; i++)
        {
            lenght += strlen(argv[i]) + 1;
        }
        ++lenght;


        char result_str [lenght];//i'm terribly sorry for the warning
        //but i don't know how to solve this without stl and dynamic stuff(even stackoverflow doesn't)(

    result_str[0] = '\0';
        for (int i = 2; i < argc; i++)
        {
            strcat(result_str, argv[i]);
            if (i != argc - 1)
            {
                strcat(result_str, " ");
            }
        }
        Functor_Sort obj;
        obj.Show_str(result_str);
        std::cout << "///////////" << std::endl << std::endl;
        obj(result_str);
        std::cout << "///////////" << std::endl << std::endl;
        obj.Show_str(result_str);
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
