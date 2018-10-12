#include "FunctorExponent.h"
#include <iostream>

int main(){

    FunctorExponent f(2,-1);
    std::cout << f() << std::endl;

    return 0;
}
