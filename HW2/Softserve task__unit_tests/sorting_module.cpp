#include "sorting_module.h"

Sorting_module::Sorting_module()
{

}

void Sorting_module::selection_sort(std::vector<std::string> &v)
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
        v[i] = temp.front();
        temp.clear();
        }
}
