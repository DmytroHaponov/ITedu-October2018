#include<iostream>
#include<vector>

int main()
{
    int res = 0;
    int pal = 0;
    int max_pal = 0;
    int x1, x2, x3, x4, x5, x6 = 0;
    std::vector<int> v;

    for (int i = 100; i < 1000; i++)
    {
        for (int k = 100; k < 1000; k++)
        {
            res = k * i;

            //result divider
            x1 = res / 100000;
            x2 = (res - x1 * 100000) / 10000;
            x3 = (res - x1 * 100000 - x2 * 10000) / 1000;
            x4 = (res - x1 * 100000 - x2 * 10000 - x3 * 1000) / 100;
            x5 = (res - x1 * 100000 - x2 * 10000 - x3 * 1000 - x4 * 100) / 10;
            x6 = (res - x1 * 100000 - x2 * 10000 - x3 * 1000 - x4 * 100 - x5 * 10);

            //pushing palindrome to vector
            if (x1==x6 && x2==x5 && x3==x4)
            {
                pal = x1 * 100000 + x2 * 10000 + x3 * 1000 + x4 * 100 + x5 * 10 + x6;
                v.push_back(pal);
            }
        }
    }

    //finding maximal paindrome
    max_pal = v[0];

    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (v[i] >= max_pal)
        {
            max_pal = v[i];
        }
    }

    std::cout << "Amount of palindromes = " << v.size() << std::endl;
    std::cout << "Maximal palandrome of two 3-digit numbers = " << max_pal << std::endl;

    return 0;
}

