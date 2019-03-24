#include <iostream>

double exp(int a,int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    if (a==0)
    {
        std::cout << "Incorrect data" << std::endl;
        return 1/0;
    }
    if (b<0)
    {
        return 1/exp(a,-b);
    }
    return exp(a,b-1)*a;
}


int main()
{
    int a{0},b{0};
    std::cout << "Input number a ";
    std::cin  >> a;
    std::cout << "Now input exp ";
    std::cin  >> b;
    std::cout << std::endl <<"result " << exp(a,b) << std::endl;
    return 0;
}
