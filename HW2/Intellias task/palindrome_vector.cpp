#include <vector>
#include <iostream>
int len(int num);
int seeking_the_num();
bool palindrome(int num);

int main ()
{
    std::cout << "Result: " << seeking_the_num() << std::endl;

    return 0;
}

int seeking_the_num()
{
    int count(0);
    int multip(0);
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
}

bool palindrome(int num)
{
    std::vector<int> Vec;
    int temp = 0;
    int num_len = len(num);

    while (num != 0)//заполняем вектор числами
    {

        temp = num % 10;
        num /= 10;
        Vec.push_back(temp);
    }

    int read_from_end = num_len;

    for (int i = 0; i < num_len/2; i++)//проверка на палиндром
    {
        read_from_end--;
        if (Vec[i] != Vec[read_from_end])
        {
            return 0;
        }
    }
    return 1;
}
int len(int num)//ищем длину числа
{
    int len(0);
    do
    {
        num /= 10;
        len += 1;
    }
    while(num > 0);
    return len;
}