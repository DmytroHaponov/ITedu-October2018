#include <iostream>

using namespace std;

int main()
{
    int n4=0;
    int n3=0;
    int n2=0;
    int P_LARGEST=0;
    int sum;
    for (int i = 999; i > 100; --i)
    {
        for (int j = 999; j > 100; --j)
        {
            sum = i * j;
            int temp = sum; // Initial number
            int b = 0; // The number is invert
            while (temp != 0)
            {
                b = b * 10 + temp % 10; // Flipping a number by numbers
                temp /= 10; // Drop the last digit
            }
            if (sum == b)
            {
                int n1=sum;
                if(n1>n2)
                {
                    P_LARGEST=sum;
                    n2=P_LARGEST;
                    n3=i;
                    n4=j;
                }
            }
        }
    }
    std::cout << "Largest polindrom! "<< P_LARGEST<<"\n"<<"Number1: "<<n3<<"\n"<<"Number2: "<<n4<< std::endl;
    return 0;
}
