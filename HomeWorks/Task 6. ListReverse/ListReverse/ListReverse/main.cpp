#include <iostream>

#include "list.h"

int main()
{
    List list;

    list.GenerateList(5);
    list.Show();

    list.Reverse();
    list.Show();

    return 0;
}
