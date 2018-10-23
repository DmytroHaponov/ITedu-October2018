#include "sortNamesSTL.h"


SortNamesSTL::SortNamesSTL(){}

//writing in file 5k names//
void SortNamesSTL::WriteToFile(){
    std::string arr[81] = {"Peter", "Katya", "Ann", "Steve", "John"};
    std::ofstream fileo("Names");
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
    std::ifstream file("Names");
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
    std::ifstream file("Names");
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
    for(const auto& i : MySet){
        std::cout << i << std::endl;
    }
        std::cout << std::endl;
    }

//destructor//
SortNamesSTL::~SortNamesSTL(){
    names.clear();
    MySet.clear();
}

//output in console//
void SortNamesSTL::PrintDeque(){
    for(const auto& i : names){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}
