#include "vector_functions.h"

int main()
{
    std::vector<int> vect;

    fillVector(vect, 12);

    bool res = hasVectorOdd(vect);

    for(const auto& num : vect)
    {
        std::cout << num << ' ';
    }

    std::cout << std::endl;

    if(res)
    {
        std::cout << "Vector has odd number" << std::endl;
    }
    else
    {
        std::cout << "All numbers are even" << std::endl;
    }

    return 0;
}
