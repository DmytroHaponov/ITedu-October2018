#include "namesSortWoSTL.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>

//constructor//
NamesSortWoSTL::NamesSortWoSTL(){}

//Writing in file 5k names//
void NamesSortWoSTL::AddToFile(){
    std::string arr[81] = {"Peter ", "Katya ", "Ann ", "Steve ", "John "};
    std::ofstream fileo("/home/ngb/Desktop/C++/HW/Names/name");
    if(fileo.is_open()){
        for(int i = 0; i < 1000; i++){
            for (int j = 0; j < 5; j++){
                fileo << arr[j];
            }
        }
        std::cout <<std::endl;
    }
    else {
        std::cout << "Can't write data" << std::endl;
    }
    fileo.close();
}

//writing names from file to string array//
    std::string NamesSortWoSTL::ReadFromFile(){
    std::ifstream file("/home/ngb/Desktop/C++/HW/Names/name");
    if (file.is_open()){
        for (int i = 0; i < size-1; i++){
        file >> temp;
        names[i] = temp;
        }
    }
    else{
        std::cout << "Something gone wrong!" << std::endl;
    }
    file.close();
    return *names;
}
    //writing to char array for calculate weight//
    char NamesSortWoSTL::WriteToArray(){
        std::ifstream file("/home/ngb/Desktop/C++/HW/Names/name");
        if (file.is_open()){
            file.get(ascii,len);
        }
        else{
            std::cout << "Something gone wrong!" << std::endl;
        }
        file.close();
        return *ascii;
    }

//sorting//
void NamesSortWoSTL::Sort(){

    std::sort(std::begin(names),std::end(names));
}

//print names//
void NamesSortWoSTL::Print(){
    for(int i = 0; i < size-1; ++i){
        std::cout <<  names[i] << ' ';
    }
    std::cout << std::endl;
}

//destructor//
NamesSortWoSTL::~NamesSortWoSTL(){
    delete[] &names;
    delete[] &temp;
    delete[] ascii;
}

//calculate weight of all symbols//
std::size_t NamesSortWoSTL::GetWeight(){
    std::size_t result = 0;
    std::size_t counter = 0;
    std::size_t value[len];
    for(int i = 0; i < len-1; ++i ){
        value[i] = (std::size_t)ascii[i];
        if(value[i] > 32){
            result = value[i];
            result = result - 64;
            counter += result;
        }
    }
    std::cout<< counter << ' ';
    return counter;//вне цикла не отображает подсчет, в цикле считает правильно
}





