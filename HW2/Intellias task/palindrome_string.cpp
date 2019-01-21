#include <iostream>
#include <typeinfo>

bool palindrome(int);
int seeking_the_num ();

int main ()
{
    std::cout << seeking_the_num() << std::endl;
    return 0;
}

int seeking_the_num ()
{
    int multip (0);
    int count (0);
    for (int i = 999, j = 999; i >= 100, j >= 100;)
    {
        count++;
        multip = i * j;
        if (palindrome(multip))
        {
            std::cout << "i = " << i << "; j = " << j << std::endl;
            return multip;
        }
        if (count % 2 == 0)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    return 0;
}

bool palindrome(int multip)
{
    auto s = std::to_string(multip);
    //std::cout << multip << typeid(multip).name() << std::endl;
    int read_from_end = s.length();
    //bool result (1); //переменная, что отвечает проверку будет ли число по
    for (int i = 0; i < (s.length()/2); i++)
    {
        read_from_end--;
        if (s[i] != s[read_from_end])
        {
            return 0;//result = 0;
        }
    }
    return 1;//result;
}