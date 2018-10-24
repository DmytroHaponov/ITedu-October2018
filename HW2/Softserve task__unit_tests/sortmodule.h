#ifndef SORTMODULE_H
#define SORTMODULE_H

#include <string>
#include <iostream>
#include <algorithm>
#include <deque>

/*
    I made some changes to functions from HW1.
    Added two new function which write data from array to string/deque.
    Added new arguments to adapt functions to a variety of variables(string,deque).
*/

//previous declaration for functions//
    void addDeque(std::deque<std::string> &str);
    void add(std::string *str);
    void SortDeque(std::deque<std::string> &str);
    void merge(int low, int mid, int hight, std::string *names);
    void mergeSort(int low, int hight, std::string *str);

//declarations variables to tests//
    static std::string *names1 = new std::string[81];
    static std::string *names2 = new std::string[81];
    static std::string *names3 = new std::string[81];
    static std::string *tmp = new std::string[81];
    static std::string arr[81] = {"Peter", "Katya", "Ann", "Steve", "John"};
    static std::deque<std::string> Names1;
    static std::deque<std::string> Names2;
    static std::deque<std::string> Names3;

//add words to deque// NEW function
    void addDeque(std::deque<std::string> &str){
        for(int i = 0; i < 81; i++){
            str.push_back(arr[i]);
        }
    }

//add words to string//NEW function
    void add(std::string *str){
        for(int i = 0; i < 81; i++){
            for (int j = 0; j < 5; j++){
                str[i] = arr[j] ;
            }
        }
    }

//merge sort function// NEW: in arguments add pointer on string//
    void mergeSort(int low, int hight, std::string *str ){
        int mid = 0;
        if(low < hight){
            mid = ((low+hight)/2);
            mergeSort(low, mid, str);
            mergeSort(mid+1, hight, str);
            merge(low, mid, hight, str);
        }
    }

//merge function for merge sort function// NEW: in arguments add pointer on string//
    void merge(int low, int mid, int hight, std::string *names){
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

//Algorithm sort deque// NEW: in arguments add variable to deque//
    void SortDeque(std::deque<std::string> &str){
        std::stable_sort(str.begin(), str.end());
    }


#endif // SORTMODULE_H
