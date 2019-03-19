#include "vector_functions.h"

void fillVector(std::vector<int>& vect, int n)
{
    for(int i{0}; i < n; ++i)
    {
        bool todo = false;
        int num{0};
        while (!todo)
        {
            todo = true;
            num = rand() % (n * 2);
            for(int i{0}; i < vect.size(); ++i)
            {
                if(vect.at(i) == num)
                {
                    todo = false;
                }
            }
        }
        vect.push_back(num);
    }
}

bool hasVectorOdd(std::vector<int>& vect)
{
    if (std::all_of(vect.cbegin(), vect.cend(), [](int i){ return i % 2 == 0; }))
    {
        return false;
    }

    return true;
}
