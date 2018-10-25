#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#endif // FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void file_write(std::string msg)
{
    std::fstream file;
    file.open("file.txt", std::fstream::out | std::fstream::binary | std::fstream::app);

    if(!file.is_open())
    {
      std::cout<<"Error opening file!"<<std::endl;
    }
    file<<msg;

    file.close();
}

std::string file_read(long long int &r_pos, int &s_count, int &s_num)
{
    char buf = '0';
    std::string msg;
    std::fstream file;

    file.open("file.txt", std::fstream::in | std::fstream::binary);

    if(!file.is_open())
      {
        std::cout<<"Error opening file!"<<std::endl;
      }

    file.seekp(r_pos);

    while(buf != ' ')
    {
        file.get(buf);
        msg += buf;
        s_count += static_cast<int>(buf) ;
        s_num = static_cast<int>(buf);
    }

    r_pos=file.tellg();

    return msg;
}

void selection_sort(std::vector<std::string> &v)
{
    std::vector<std::string> temp;
    unsigned int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < v.size(); i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;

        for (j = i+1; j < v.size(); j++)
        {
            if (v[j] < v[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        temp.push_back(v[min_idx]);
        v[min_idx] = v[i];
        v[i] = temp[0];
        temp.clear();
        }
}
