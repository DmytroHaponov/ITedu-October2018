#include <namesSortWoSTL.h>


int main(){

    NamesSortWoSTL NS;
    NS.AddToFile();
    NS.ReadFromFile();
    NS.WriteToArray();
    NS.mergeSort(0,4999);
    NS.merge(0,2500,4999);
    NS.Print();
    std::cout << NS.GetWeight() << std::endl;

    return 0;
}
