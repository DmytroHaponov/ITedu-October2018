#include "rails.h"

/*
 * Program build matrix, insert lines and search free cells in char array[][];
*/


//create char array[row][columns] and write in all cells symbol 'o'//

Rails::Rails(const int& row, const int& column,
             const int& rails)
    : n(row), m(column), k(rails){

    if(n >= 1 && m <= 1000000000 && m >= 1 && k >= 0 && k <= 1000){
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
        std::cout << "Error!!!" << std::endl;
    }
}

//function insert in cells "rails"//

void::Rails::pushRails(const int& row, const int& begin,
                       const int& end){
    r = row;
    c1 = begin;
    c2 = end;

    if(r >= 1 && r <= n && c1 >= 1 && c1 <= m && c2 >= 1 && c2 <= m){
        for(int j = (c1-1); j <= (c2-1); j++){
            ptrArray[r-1][j] = 'i';
        }
    }
    else{
        std::cout << "Error2!!!" << std::endl;
    }
}

//function search cells without rails//

void::Rails::searchFree(){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ptrArray[i][j] == 'o'){
            counter++;
            }
        }
    }
}

//output result to console//

void::Rails::print(){
    std::cout << counter << std::endl;
}

//return memory for deallocate//

Rails::~Rails(){
    for(int i = 0; i < n-1; i++){
        delete[]ptrArray[i];
    }
}

//function return amount of free cells//
int::Rails::GetCounter(){
    return counter;
}
