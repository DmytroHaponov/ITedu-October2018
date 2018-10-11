#include "header.h"
//#include <fstream>
int generate_file(char *name)
{
    srand(time(NULL));

    //std::string name;
    //char name [20];
    std::ofstream fout;

    std::cout << "Enter the name of the file: ";
    std::cin >> name;

    //очистка потока//
    std::cin.clear();
    std::cin.ignore(2, '\n');

    fout.open(name);//, std::ofstream::app);

    //ПРОВЕРКА ОТКРЫТИЯ//
    if (!fout.is_open())
    {
        std::cout << "File openning error" << std::endl;
        //return;
        exit(1);
    }

    int word_number = 10;
    char sep = ' ';

    std::cout << "Input a number of words: ";
    std::cin >> word_number;
    int words = word_number;
    std::cout << "Input a separator [0-' ', 1 - '/n', 2 - '/t']: ";
    std::cin >> sep;
    switch (sep)
    {
    case '0':
        sep = ' ';
        break;
    case '1':
        sep = '\n';
        break;
    case '3':
        sep = '\t';
        break;
    default:
        // std::cout << "Bad INput";
        // return;/..or../exit(1);
        sep = '\n';
    }

    //очистка потока//
    std::cin.clear();
    std::cin.ignore(10, '\n');
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int letter_number = 0;
    int index = 0;//индекс рандомной буквы в массиве всех возможных букв для задания имен
    char allletters[16] = "esytumiporvaskc";
    char ALLLETTERS[16] = "ESYTUMIPORVASKC";
    char current_letter;//буква которая будет записана в файл, т. к. запись производится побуквенно

    while (word_number > 0)
    {
        letter_number = rand()%7 + 4;//букв в слове
        for (int i = 1; i <= letter_number; i++)
        {
            index = rand()%15;//16 - кол-во элементов в массиве букв, а 15 - индекс 16 элемента//рандомим букву

            i == 1 ? current_letter = ALLLETTERS[index] : current_letter = allletters[index];// 1я буква будет заглавной

            fout << current_letter;
        }

        fout << sep;//??????????\\\\n
        word_number--;
    }
    fout.close();
    return words;
}

void read_from_file(char **names,int words_number,char filename[])//, std::string filename)
{
    std::ifstream fin;
    //std::string name; //строка для хранения имен в массиве;
    //char name[10];
    fin.open (filename);

    if (!fin.is_open())
    {
        std::cout << "File reading error";
        exit(1);
    }

    int i = 0;
    while (!fin.eof())
    {

        if (i < words_number)
        {
            fin >> names[i];
            //names[i] = name;
//            for (unsigned int k = 0; k < strlen(name); k++)
//            {
//                std::cout << name[k] << '\n';
//                names[i][k] = name[k];
//            }
            std::cout << names[i] << std::endl;
            i++;
        }
        else
        {
            break;
        }
    }
//    for (int i = 0; i < 10; i++)
//    {
//        name[i] = 'b';
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        std::cout << name[i];
//    }
//    std::cout << '\n';
    std::cout << "\\\\\\////\n";
    for (int j = 0; j < words_number; j++)
    {
        std::cout << names[j] << std::endl;
//        for (int i = 0; i < strlen(names[j]); i++)
//        {
//            std::cout << names[j][i];
//        }
//        std::cout << '\n';
    }
    fin.close();
}

void assign_string(char array1[], char tobeassigned[]) //функция присвоения одной строки другой//
{
    int i = 0;
    while (array1[i] != '\0') //&& tobeassigned[i] != '\0')
    {
        array1[i] = tobeassigned[i];//
        i++;
    }
}


bool compare (char array1[], char array2[])
{
    int len = 0;
    char alphab_cap[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char alphab[] = "zyxwvutsrqponmlkjihgfedcba";

    int counter1 = 0, counter2 = 0;

    if (strcmp(array1, array2) < 0)//ищем наименьшую строку
        len = strlen(array1);//array1 наименьший
    else
        len = strlen(array2);//array2 наименьший

    for (int i = 0; i < len; i++)//
    {
        counter1 = is_in(array1[i], alphab, alphab_cap);
        counter2 = is_in(array2[i], alphab, alphab_cap);
        if (counter1 > counter2)
        {
            return 1;
        }
        else if (counter1 < counter2)
        {
            return 0;
        }
    }
     //если вышли из цикла, значит слова равны, но одно из них возможно короче. Ищем короткое слово
     if (len == strlen(array1))//если первое слово оказалось короче, то такое слово идет первым в алфавитном порядке
     {
         return 1;
     }
     return 0;
}


void sort(char **array,const int &number_of_elements)
{
    char string[10];
    for (int i = 0; i < number_of_elements; i++)
    {
        for (int j = i; j < number_of_elements; j++)
        {
            if (compare(array[i], array[j]) == 0)
            {
               assign_string(string, array[j]);//equel to string  = array[j];
               assign_string(array[j],array[i]);
               assign_string(array[i],string);

            }
        }
    }
}


int is_in (char n, char alphab[], char alphab_cap[])
{
    char count = 0;
    while (alphab[count] != '\0')
    {
        if (alphab[count] == n)
            return count;
        count++;
    }
    count = 0;
    while (alphab_cap[count] != '\0')
    {
        if (alphab_cap[count] == n)
            return count;
        count++;
    }
}

int hash (char **names,int number_words)//вторая переменная отвечает за к-во слов;
{
    int temp = 0;
    int count = 0; //переменная для сбора аски символов всех букв в слове
    for (int j = 0; j < number_words; j++)
    {
        //for (int i = 0; i < 10; i++)
        int i = 0;
        while (names[j][i] != '\0')
        {
            //count += names[j][i];
            temp += static_cast<int>(names[j][i]);
            //std::cout << names[j][i] << std::endl;
            i++;
        }
        temp /= i;
        count += temp;
        temp = 0;
    }
    return count;
}

void write_in_file(char **names, int words_number)//, char sep = '\n')
{
    std::ofstream fout;
    fout.open("SortedFile.txt");
    if (!fout.is_open())
    {   std::cout << "Openning file Error";
        exit(1);
    }
    for (int i = 0; i < words_number; i++)
    {
        fout << names[i] << '\n';
    }

    fout.close();
}

char** gen_2d_array(int words_number)
{
    char **namelist = new char*[words_number];
    for (int i = 0; i < words_number; i++)
    {
        namelist[i] = new char[10];
    }
    return namelist;
}
