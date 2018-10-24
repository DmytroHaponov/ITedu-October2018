#include <iostream>
#include <functions.h>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int w_amnt = 0;

    std::cout << "Enter the amount of words: ";
    std::cin >> w_amnt;

    std::cout<<"\n";

    //generate words and writing to file
    for(int i=0; i<w_amnt; i++)
    {
        std::string buf;
        for(int w=0;w<10;w++)
        {
            buf+='A'+rand()%26;
        }
        buf+=' ';
        file_write(buf);
    }

    //read file and push back vector
    long long int r_pos=0;
    int count=0;
    int s_num=0;

    std::vector<std::string> v;

    for(int i=0;i<w_amnt;i++)
    {
        v.push_back(file_read(r_pos, count, s_num));
    }

    //sorting vector
    selection_sort(v);

    for(auto i: v)
    {
        std::cout << i << std::endl;
    }

    std::cout<<"\n";

    //"weight" of words count

    std::cout<<"Summary of symbol index = "<<count<<"\n\n";

    return 0;
}
