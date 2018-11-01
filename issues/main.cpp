
#include <iostream>
#include <thread>
#include <vector>

int task1(int value)
{
    ++value;
    return value;
}
int main()
{

    int a = 10;

    std::vector<std::thread> threads;

    for (unsigned int i = 0; i < std::thread::hardware_concurrency(); i++)
    {
        threads.push_back(std::thread(task1, a));
    }

    for (auto& i : threads)                       //i=err
    {    
        i.join();
    }

    std::cout << a << std::endl;
}
