#include "functions.h"

double my_pow(int base, int exponent)
{
    double res = base;
    bool minus = false;

    if(base == 0)
    {
        return 0;
    }

    if(exponent == 0)
    {
        return 1;
    }

    if(exponent < 0)
    {
        minus = true;
        exponent *= -1;
    }

    for(int i{0}; i < exponent - 1; ++i)
    {
        res *= base;
    }

    if(minus)
    {
        res = 1 / res;
    }

    return res;
}
