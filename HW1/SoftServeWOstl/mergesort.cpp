#include "mergesort.h"

/*
 * Program input string and sort it with merge sort algorithm
*/

StringSort::StringSort(){}

//function sort string with merge sort algorithm//

void StringSort::mergeSort(int low, int hight){
    int mid = 0;
    if(low < hight){
        mid = ((low+hight)/2);
        mergeSort(low, mid);
        mergeSort(mid+1, hight);
        merge(low, mid, hight);
    }
}

//merge sort algorithm//

void StringSort::merge(int low, int mid, int hight){
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= hight){
        if(names[i] < names[j]){
            tmp[k].assign(names[i]);
            i++;
        }
        else{
            tmp[k].assign(names[j]);
            j++;
        }
        k++;
    }
        if(i > mid ){
            for(int h = j; h <= hight; h++){
                tmp[k].assign(names[h]);
                k++;
            }
       }
        else
           for(int h = i; h <= mid ; h++){
               tmp[k].assign(names[h]);
               k++;
           }
           for(int i = low; i <= hight ; i++){
                names[i].assign(tmp[i]);
           }
}

//output in console//

void StringSort::print(){
    for(int i = 0; i < len; i++){
        std::cout << names[i];
    }
}

//return memory//

StringSort::~StringSort(){
    delete[]names;
    delete[]tmp;
}

//copy strings//

std::string StringSort::add(const std::string *str){
    for(int i = 0; i < len; i++){
        names[i] = str[i];
    }
    return *names;
}


