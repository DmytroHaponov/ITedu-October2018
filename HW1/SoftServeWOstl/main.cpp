#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <fstream>


int main(){
    char output;
    std::string roster="ABCDEFGHIJKLMNOPQRSTUVWYZabcdefghijklmnopqrstuvwyz";
    unsigned int ROSTER_SIZE=roster.size();
    unsigned int nameLength(0);
    unsigned int nameN(0);
    std::string currName;
    std::cout<<"Enter the name length: ";
    std::cin>>nameLength;

    std::cout<<"Enter the total number of names: ";
    std::cin>>nameN;
    unsigned int i(0),j(0);
    /*
    std::ofstream names_in("names.txt");
    if(!names_in){
        std::cout<<"Unable to open the file.\n";
        return EXIT_FAILURE;
    }
    for(;i<nameN;i++){
        for(;j<nameLength;j++){
            //srand(time_t(nullptr));
            output=roster.at(std::rand()%ROSTER_SIZE);
            currName+=output;//⍰чого він не переповнюється?
        }
        std::random_shuffle(currName.begin(),currName.end());
        names_in<<currName<<std::endl;//write into file!
    }
    names_in.close();
*/
    //std::cout<<"Size of one name is "<<currName.length()<<'\n';

    std::fstream names_sort("names.txt",std::ios::in|std::ios::out);
    if(!names_sort){
        std::cout<<"Unable..."<<'\n';
        return EXIT_FAILURE;
    }
    std::string st1;//set max capacity? Initialize?
    std::string st2;
    std::string min(nameLength,'~');
    unsigned minpos(0);
    for(i=0;i<nameN-1;i++){
        names_sort.seekg(i*(nameLength+2),std::ios::beg);
        names_sort>>st1;
        min=st1;
        //std::cout<<st1<<std::endl;
        for(j=i+1;j<nameN;j++){
            names_sort.seekg(j*(nameLength+2),std::ios::beg);
            names_sort>>st2;
            if(st2<min){
                min=st2;
                minpos=j*(nameLength+2);
            }
            //std::cout<<st2<<std::endl;
        }
        if(st1>min){
            names_sort.seekp(i*(nameLength+2),std::ios::beg);
            names_sort<<min<<std::endl;
            names_sort.seekp(minpos,std::ios::beg);
            names_sort<<st1<<std::endl;
        }
    }
    names_sort.close();


    return EXIT_SUCCESS;
}
