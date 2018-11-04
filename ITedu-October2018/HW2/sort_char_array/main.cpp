#include "iostream"
#include "algorithm"
#include "set"


class MyFunctor
{
public:
    void operator()(char arr[],const int size)
    {
        std::set<char>char_sort;
        for (int i = 0; i <= size; i++)
        {
            char_sort.insert(arr[i]);
        }
        for (const auto &i: char_sort)
        {
            std::cout << i << std::endl;
        }
    }
};
int main()
{
    const int size_arr=10;
    char arr[size_arr] = { 'd','c','o','a','s','f','g','e','v','u' };
    MyFunctor fy;
    fy(arr,size_arr);
    system("pause");
    return 0;
}
