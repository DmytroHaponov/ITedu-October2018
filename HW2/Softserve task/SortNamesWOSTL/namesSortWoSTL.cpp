#include "namesSortWoSTL.h"

NamesSortWoSTL::NamesSortWoSTL(){}

void NamesSortWoSTL::AddToFile(){
    std::string arr[81] = {"Peter ", "Katya ", "Ann ", "Steve ", "John "};
    std::ofstream fileo("name");
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

    std::string NamesSortWoSTL::ReadFromFile(){
    std::ifstream file("name");
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
        std::ifstream file("name");
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
    void NamesSortWoSTL::mergeSort(int low, int hight){
        int mid = 0;
        if(low < hight){
            mid = ((low+hight)/2);
            mergeSort(low, mid);
            mergeSort(mid+1, hight);
            merge(low, mid, hight);
        }
    }

    void NamesSortWoSTL::merge(int low, int mid, int hight){
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

//print names//
void NamesSortWoSTL::Print(){
    for(int i = 0; i < size-1; ++i){
        std::cout <<  names[i] << ' ';
    }
    std::cout << std::endl;
}

//destructor//
NamesSortWoSTL::~NamesSortWoSTL(){
    delete[] ascii;
    delete[] names;
    delete[] tmp;
}

//calculate weight of all symbols//
int NamesSortWoSTL::GetWeight(){
    int result = 0;
    int counter = 0;
    int value[len];
    for(int i = 0; i < len-1; ++i ){
        value[i] = (std::size_t)ascii[i];
        if(value[i] > 32 && value[i] >= 65 && value[i] < 123){
            result = value[i];
            result = (result - 64);
            counter += result;
        }
    }
    return counter;
}





