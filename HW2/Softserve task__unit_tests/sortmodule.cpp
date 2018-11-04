#include "sortmodule.h"

sortModule::sortModule()
{

}
void sortModule::quickSort(std::string *arr, int left,int right)
{
    int i = left, j = right;
    std::string pivot = arr[(left + right) / 2];
    /* partition */

    while (i <= j) {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            std::string tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j)

        quickSort(arr, left, j);

    if (i < right)

        quickSort(arr, i, right);

}

