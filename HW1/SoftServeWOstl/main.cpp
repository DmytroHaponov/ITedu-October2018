#include <iostream>
#include<functions.h>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    //generate words and writing to file
    for(int i=0; i<5000; i++)
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

    for(int i=0;i<5000;i++)
    {
        v.push_back(file_read(r_pos, count, s_num));
    }

    //sorting vector
    sort(v.begin(),v.end());

    for(size_t i=0;i<v.size();i++)
    {
        std::cout<<v[i]<<std::endl;
    }

    std::cout<<"\n";

    //weight count

    std::cout<<"Summary of symbol index = "<<count<<std::endl<<std::endl;

    return 0;
}
