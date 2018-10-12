#include "sortNamesSTL.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <deque>
#include <iterator>

//constructor//
SortNamesSTL::SortNamesSTL(){}

//writing in file 5k names//
void SortNamesSTL::WriteToFile(){
    std::string arr[81] = {"Peter", "Katya", "Ann", "Steve", "John"};
    std::ofstream fileo("/home/ngb/Desktop/C++/HW/SortNames/Names");
    if(fileo.is_open()){
        for(int i = 0; i < 1000; i++){
            for (int j = 0; j < 5; j++){
                fileo << arr[j] << ' ';
            }
        }
    std::cout << std::endl;
    }
    else {
        std::cout << "Can't write data" << std::endl;
    }

    fileo.close();
}

//writing names to deque//
void SortNamesSTL::ReadFromFile(){
    std::ifstream file("/home/ngb/Desktop/C++/HW/SortNames/Names");
    std::string str;
    if (file.is_open()){
        for (int i = 0; i < 5000; i++){
            file >> str;
            names.push_back(str);
        }
    }
    else{
        std::cout << "Something gone wrong!" << std::endl;
    }
    file.close();
}

//sorting names in deque//
void SortNamesSTL::SortDeque(){
    std::stable_sort(names.begin(), names.end());
}

//writing names and sorting in set//
void SortNamesSTL::GetSet(){
    std::ifstream file("/home/ngb/Desktop/C++/HW/SortNames/Names");
    std::string str;
    if (file.is_open()){
        for (int i = 0; i < 5000; i++){
            file >> str;
            MySet.insert(str);
        }
    }
    else{
        std::cout << "Something gone wrong!" << std::endl;
    }
    file.close();
}

//output in console//
void SortNamesSTL::PrintSet(){
        copy( MySet.begin(), MySet.end(), std::ostream_iterator<std::string>(std::cout,"\n") );
        std::cout << std::endl;
    }

//destructor//
SortNamesSTL::~SortNamesSTL(){
    delete[] &names;
    delete[] &MySet;
}

//output in console//
void SortNamesSTL::PrintDeque(){
    copy( names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout,"\n") );
    std::cout << std::endl;
}
