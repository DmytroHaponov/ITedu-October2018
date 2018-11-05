#ifndef MYFUNCTOR_H
#define MYFUNCTOR_H

#include <set>
#include <iostream>
#include <algorithm>
class MyFunctor
{
public:
    void operator()(char arr[],const int size)
    {
        if(size==0)
        {
            return;
        }
        int n=0;
        std::set<char>char_sort;
        for (int i = 0; i < size; i++)
        {
            char_sort.insert(arr[i]);
        }
        for (int i = 0; i < size; i++)
        {
            auto it=char_sort.begin();
            std::advance(it,n);
            arr[i]=*it;
            ++n;
        }
    }
};

#endif // MYFUNCTOR_H
