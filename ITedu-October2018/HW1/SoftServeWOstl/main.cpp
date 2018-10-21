#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

std::string sort(std::string str[],int size_arr)
{
// сортируем массив строк
std::string tmp="";
for(int i=0;i<size_arr;i++)
 {
  for(int j=i;j<size_arr;j++)
   {
    if(str[i]>str[j])
      {
         tmp=str[i];
         str[i]=str[j];
         str[j]=tmp;
       }
    }
 }
for (int i = 0; i < size_arr; i++)
{
    std::cout<<str[i]; //вывод массива после сортировки
}
}

int main()
{
//srand(time_t(nullptr));
char abc[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','N','M','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
std::string backspace = " ";
std::string Allwords[5000];                                 //создаем 5000 тыс слов разной длины(использую слова только вверхнего регистра), с пробелами в конце каждой строки
const int size = 5000;                                      //
std::string eachString;                                     //
        for (int i = 0; i < size; i++)                      //
        {                                                   //
            for (int j = 0; j < rand() % 10 + 3; j++)       //
            {                                               //
                eachString += (abc[rand() % 26]);           //
            }                                               //
            if (eachString.size() > 2)                      //
            {                                               //
                eachString += backspace;                    //
                Allwords[i]+=eachString;                    //
                eachString.clear();                         //
            }                                               //

        }                                               //-------------//
std::string path="C:\\Users\\Andrey\\Desktop\\words.txt";       //
std::ofstream words;                                            //записываем имена в существующий файл
    words.open(path);                                           //
    if(!words.is_open())                                        //
    {                                                           //
        std::cout<<"Error"<<std::endl;                          //
    }                                                           //
    else                                                        //
    {                                                           //
        std::cout<<"File is open for note"<<std::endl;          //
        for(int j=0;j<size;j++)                                 //
        {                                                       //
            words<<Allwords[j];                                 //
        }                                                       //
    }                                                           //
    words.close();                                              //

                                                         //-------------//
std::string buf;     //буфер для считывания слов                //
std::ifstream fin;                                              //считывания имена из файла в буферную строку
fin.open(path);                                                 //
if(!fin.is_open())                                              //
{                                                               //
    std::cout<<"Error"<<std::endl;                              //
}                                                               //
else                                                            //
{                                                               //
    std::cout<<"File is open for reading"<<std::endl;           //
    while(fin)                                                  //
       {                                                        //
            std::getline(fin, buf);                             //
       }                                                        //
}                                                               //
fin.close();                                                    //выводим строку до сортировки
std::cout<<buf<<std::endl;                                      //
std::cout<<"--------------------"<<std::endl;           //-------------//
std::string AllWords_two[5000];                                 //пересобираем строку обратно в массив по слову в каждом индексе для удобной сортировки
int k=0;      //индекс каждой ячейки массива                    //
int word_begin=0,word_end=0;                                    //
for (int i=0; i<buf.length();i++)                               //
  {                                                             //
    if(buf[i]==' ' || i==buf.length()-1)                        //
    {                                                           //
      word_end=i;                                               //
      for(int j=word_begin;j<word_end;j++)                      //
       AllWords_two[k]+=buf[j];                                 //
       AllWords_two[k]+=backspace;                              //
      k++;                                                      //
      word_begin=word_end+1;                                    //
    }                                                           //
  }                                                             //
                                                          //-------------//
                                                                //
sort( AllWords_two,size);                                       //функция сортировки массива слов
                                                                //
system("pause");
return 0;
}

