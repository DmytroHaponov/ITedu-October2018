#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

namespace generator
{
    int SizeFile;
    //есть проблема с кодировкой поэтому перепишу в английскую раскладку
    //char BigSymvol[] = "АБВГҐДЕЄЖЗІКЛМНОПРСТУФХЦЧШЩЮЯ";
    int MaxBig = 26;
    char BigSymvol[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //char SmalSymvol[] = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
    int MaxSmal = 26;
    char SmalSymvol[] = "abcdefghijklmnopqrstuvwxyz";

int createFile(int argc, char** argv)
{

    //setlocale(LC_ALL,".1251");

    //для универсальності задамо питання кількості слів
    int LenghFile{5000},i = 0,LenghName = 3;
    std::string LastName;
    std::string NimberString{""};

    //std::cout << "Скільки імен згенерувати?:\n";
    //std::cin>>LenghFile;
    std::srand ( time(NULL) );

    if (LenghFile < 1) return 0 ;

     // создаем файл (дублирую флаги по умолчанию)
    std::ofstream NameFile("ListName.txt",std::ios_base::in | std::ios_base::trunc);

    if (!NameFile.is_open())
    {
      std::cout << "Error open file!\n" ;
      return 0 ;
    }

    for (int count = 0;count < LenghFile;count++)
    {
        LenghName = 3+rand()%7; //Оскільки ми вирішили що потрібно випадкове ім'я, то воно має бути випадковим
        LastName.clear();
        for (i = 0;i < LenghName;i++)
        {
            //srand ( time(NULL) );
            if (i==0) //Велика літера
                {
                LastName = LastName + (BigSymvol[ std::rand()%MaxBig ]);
                }
            else if (i<=LenghName)
            {
                LastName = LastName + (SmalSymvol[ std::rand()%MaxSmal ]);
            }         }
        
        NameFile << LastName <<"\n";
    }

    NameFile.close();                     // закриваемо файл
    SizeFile = LenghFile;
    std::cout << "Generate finish!\n" ;

    return 0;
}


bool CompareString(std::string s1, std::string s2)
{
    bool result = true;

    if (s1 < s2)
    {
        result = false;
    }

    return result;
}

int SortFile(int argc, char** argv)
{
    bool Trust = true;
    int maxSizeVector = 0;
    int SizeVector = 0;
    std::vector <std::string> SortList ;
    SortList.reserve(SizeFile);

    //setlocale(LC_ALL, ".1251");
    std::string buff1,buff2;
    std::ifstream NameFile("ListName.txt",std::ios_base::in);
    std::ofstream NameFileTemp("ListNameSort.txt",std::ios_base::out | std::ios_base::trunc);
    std::cout << "Vector size " << SizeFile<<"\n" ;
    if ((!NameFile.is_open())||(!NameFileTemp.is_open()))
    {
        std::cout << "Error open file!\n" ;
      return 0 ;
    }

    while (std::getline(NameFile, buff1))
    {
        SortList.push_back(buff1);
        maxSizeVector++;
    }
    NameFile.close();
    SizeVector = maxSizeVector;
    while(Trust)
    {
        if (SizeVector<1)
        {
            Trust = false;
            break;
        }

        for(int i = 0;i<(SizeVector-1);i++)
        {
            buff1 = SortList.at(i);
            buff2 = SortList.at(i+1);
            if (CompareString(buff1,buff2))
            {
                SortList[i]   = buff2;
                SortList[i+1] = buff1;
            }
        }
        SizeVector--;
    }

    //std::ofstream NameFileNew("ListName.txt",std::ios_base::out | std::ios_base::trunc);

    if (!NameFileTemp.is_open())
    {
      std::cout << "Error save sort file!\n" ;
      return 0 ;
    }
    for (int i =0; i < maxSizeVector;i++)
    {
        NameFileTemp << SortList[i] << "\n"; ;
    }

    NameFileTemp.close();

    return 0;
}

}

int main(int argc, char** argv)
{

    generator::createFile(argc,argv);
    generator::SortFile(argc,argv);

    return 0;
}
