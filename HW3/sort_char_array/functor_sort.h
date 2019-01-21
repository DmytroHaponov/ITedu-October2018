#ifndef FUNCTOR_SORT_H
#define FUNCTOR_SORT_H


#include <iostream>
#include <string.h>
//class Functor_Sort;
//#include "functor_sort.h"
#include <string.h>

class Functor_Sort
{
private:
public:
    void Sort(char str[]);
    void Show_str(char str[]);
    bool is_capitalized(char i);
    bool is_lower(char i);
    void remove_stuff(char str[]);//removes all the junk except spaces
    void operator()(char str[]);

};

#endif // FUNCTOR_SORT_H
