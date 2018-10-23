#include "header.h"
#include <random>

int generate_file(char *name)
{

    srandom(time(NULL));

    std::ofstream fout;

    std::cout << "Enter the name of the file: ";
    std::cin >> name;

    std::cin.clear();
    std::cin.ignore(2, '\n');

    fout.open(name);

    if (!fout.is_open())
    {
        std::cout << "File openning error" << std::endl;
        return 0;
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
        sep = '\n';
    }

    std::cin.clear();
    std::cin.ignore(10, '\n');

    int letter_number = 0;
    int index = 0;
    char allletters[16] = "esytumiporvaskc";
    char ALLLETTERS[16] = "ESYTUMIPORVASKC";
    char trashsymbols[22] = "!~#$%^&*()_+ |/.,<>+-";
    char current_letter;

    int random_trash_symbols = 0;

    while (word_number > 0)
    {
        letter_number = rand()%7 + 4;
        for (int i = 1; i <= letter_number; i++)
        {

            random_trash_symbols = rand()%10;

            if (random_trash_symbols == 1 && i != 1)
            {
                current_letter = trashsymbols[rand()%20];
            }
            else
            {
                index = rand()%15;
                i == 1 ? current_letter = ALLLETTERS[index] : current_letter = allletters[index];
            }

            fout << current_letter;
        }

        fout << sep;
        if (rand()%7 == 1 || rand()%7 == 0)
        {
            fout << trashsymbols[rand()%20];
        }
        word_number--;
    }
    fout.close();
    return words;
}

void read_from_file(char **names,int words_number,char filename[])
{
    std::ifstream fin;
    fin.open (filename);

    if (!fin.is_open())
    {
        std::cout << "File reading error";
        exit(1);
    }

    char arr_of_trash[] = "/.,:'\"1234567890|-=!?@#$%^&*()_+~`';<>{}[]";
    char small_letters[] = "qwertyuiopasdfghjklzxcvbnm";

    int i = -1;
    char letter;
    bool var_shows_new_word_starts(1);
    int k = 0;
    bool trash_indicator = 0;
    int m = 0;//added not to zero out k-counter when name is split by trash-symbols
    while (fin.get(letter))
    {
        if (letter != ' ' && letter != '\n' && letter != '\t' && letter != '\v' && !is_in_arr(letter, arr_of_trash))
        {
            m = k;
            if (trash_indicator && is_in_arr(letter, small_letters))
            {
                i--;
                k += k;
                trash_indicator = 0;
            }

            if (var_shows_new_word_starts)
            {
                i++;
                k -= m;
            }
            var_shows_new_word_starts = 0;
            std::cout << letter << '\n';
            names[i][k] = letter;
            k++;
            trash_indicator = 0;
        }
        else
        {
            trash_indicator = 1;//indicates thatthere were some trash;
            var_shows_new_word_starts = 1;

        }
    }

    std::cout << "\\\\\\////\n";
    for (int j = 0; j < words_number; j++)
    {
        std::cout << names[j] << std::endl;
    }
    fin.close();
}

void assign_string(char array1[], char tobeassigned[]) 
{
    int i = 0;
    char *ptr_arr;
    if (strlen(array1) >= strlen(tobeassigned)) 
    {
        ptr_arr = array1;
    }
    else
    {
        ptr_arr = tobeassigned;
    }
    while (ptr_arr[i] != '\0')
    {
        array1[i] = tobeassigned[i];
        i++;
    }
    ptr_arr[i] = '\0';
    ptr_arr = nullptr;
}


bool compare (char array1[], char array2[])
{
    unsigned long len = 0;
    char alphab_cap[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char alphab[] = "zyxwvutsrqponmlkjihgfedcba";

    int counter1 = 0, counter2 = 0;

    if (strcmp(array1, array2) < 0)
        len = strlen(array1);//array1 shorter
    else
        len = strlen(array2);//array2 shorter

    for (unsigned int i = 0; i < len; i++)//
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
     if (len == strlen(array1))
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
bool is_in_arr(char element_to_seek4, char* arr)
{
    bool is_in = 0;
    int count = 0;
    while (arr[count] != '\0')
    {
        if (arr[count] == element_to_seek4)
        {
            is_in = 1;
            break;
        }
        count++;
    }
    return  is_in;
}

int is_in (char n, char alphab[], char alphab_cap[])
{
    int count = 0;
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
    return count;
}

int hash (char **names,int number_words)
{
    int temp = 0;
    int count = 0; 
    for (int j = 0; j < number_words; j++)
    {
        int i = 0;
        while (names[j][i] != '\0')
        {
            temp += static_cast<int>(names[j][i]);
            i++;
        }
        temp /= i;
        count += temp;
        temp = 0;
    }
    return count;
}

void write_in_file(char **names, int words_number)
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
