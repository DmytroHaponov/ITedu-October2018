#ifndef RAILS_H
#define RAILS_H
#include <iostream>

class Rails{
private:

    int n = 0;
    int m = 0;
    int k = 0;
    int r = 0;
    int c1 = 0;
    int c2 = 0;
    int counter = 0;
    char **ptrArray = new char*[n];

public:

    Rails(const int& row, const int& column, const int& rails);
    void pushRails(const int& row, const int& begin, const int& end);
    void searchFree();
    int GetCounter();
    void print();
    ~Rails();
};

Rails::Rails(const int& row, const int& column,
             const int& rails)
    : n(row), m(column), k(rails){

    if(n >= 1 && m <= 1000000000 && m >= 1 && k <= 1000 && k >= 0){
        for(int i = 0; i < n; i++){
            ptrArray[i] = new char[m];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ptrArray[i][j] = 'o';
            }
        }
    }
    else{
        std::cout << "Error1!!!" << std::endl;
    }
}

void::Rails::pushRails(const int& row, const int& begin,
                       const int& end){
    r = row;
    c1 = begin;
    c2 = end;

    if(r >= 1 && r <= n && c1 >= 1 && c1 <= m && c2 >= 1 && c2 <= m){
        for(int j = (c1-1); j <= (c2-1); ++j){
            ptrArray[r-1][j] = 'i';
        }
    }
    else{
        std::cout << "Error2!!!" << std::endl;
    }
}

void::Rails::searchFree(){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ptrArray[i][j] == 'o'){
            counter++;
            }
        }
    }
}

int::Rails::GetCounter(){
    return counter;
}
void::Rails::print(){
    std::cout << counter << std::endl;
}

Rails::~Rails(){
    for(int i = 0; i < n-1; i++){
        delete[]ptrArray[i];
    }
}


#endif // RAILS_H
