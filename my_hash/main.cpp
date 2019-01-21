#include "addhash.h"

int main()
{
    AddHash<int> obj1(111);
    AddHash<int> obj2(222);
    size_t i = obj1.get_hash();
    std::cout << "hash of obj1: " << i << std::endl;
    i = obj2.get_hash();
    std::cout << "hash of obj2: " << i << std::endl;
    return 0;
}
