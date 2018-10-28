#include "functor_sort.h"

void Functor_Sort::Show_str(char str[])
{
    for (unsigned int i = 0; i < strlen(str); i++)
    {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
}


void Functor_Sort::remove_stuff(char str[])
{
    int len = static_cast<int>(strlen(str));
    char copy_str[len];//i'm terribly sorry for the warning
    //but i don't know how to solve this without stl(even stackoverflow doesn't)(
    int j = 0;
    int i = 0;
    while (str[i] != '\0')
    {
         if (is_capitalized(str[i]) or is_lower(str[i]) or str[i] == ' ')
         {
             copy_str[j] = str[i];
             j++;
         }
         i++;
    }
    copy_str[j] = '\0';
    strcpy(str, copy_str);
}



void Functor_Sort::operator()(char str[])
{
    remove_stuff(str);
    Sort(str);
}


void Functor_Sort::Sort(char str[])
{
    char temp = 0;
    for (unsigned int i = 0; i < strlen(str); i++)
    {
        for (unsigned int j = i; j < strlen(str); j++)
        {
            if (is_capitalized(str[i]))
            {
                if (is_capitalized(str[j]))
                {
                    if (str[i] > str[j])
                    {
                        temp = str[i];
                        str[i] = str[j];
                        str[j] = temp;
                    }
                }
                else if (is_lower(str[j]))
                {
                    if (str[i] > ('A' + (str[j] - 'a')))
                    {
                        temp = str[i];
                        str[i] = str[j];
                        str[j] = temp;
                    }
                }
            }
            else if (is_lower(str[i]))
            {
                if (is_lower(str[j]))
                {
                    if (str[i] > str[j])
                    {
                        temp = str[i];
                        str[i] = str[j];
                        str[j] = temp;
                    }
                }
                else if (is_capitalized(str[j]))
                {
                    if (str[i] > ('a' + (str[j] - 'A')))
                    {
                        temp = str[i];
                        str[i] = str[j];
                        str[j] = temp;
                    }
                }
            }
        }
    }
}


bool Functor_Sort::is_capitalized(char i)
{
    if (i >= 'A' && i <= 'Z')
    {
        return 1;
    }
    return 0;
}


bool Functor_Sort::is_lower(char i)
{
    if (i >= 'a' && i <= 'z')
    {
        return 1;
    }
    return 0;
}

