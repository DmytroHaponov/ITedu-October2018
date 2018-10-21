#include <iostream>
#include <fstream>
#include <string>
#include <namesSortWoSTL.h>


int main(){

    NamesSortWoSTL NS;
    NS.AddToFile();
    NS.ReadFromFile();
    NS.WriteToArray();
    NS.Sort();
    NS.Print();
    NS.GetWeight();
    NS.~NamesSortWoSTL();


    return 0;
}
