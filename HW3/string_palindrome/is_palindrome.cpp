#include "is_palindrome.h"

bool Is_Palindrome::operator()(std::string &s)
{
    std::string str = s;
    this->to_lower(str);
    this->remove_stuff(str);//!!!!
    return is_palindrome(str);
}
bool Is_Palindrome::is_palindrome(std::string &str)
{
    if (str[0] == '\0')
    {
        return false;
    }
    for (unsigned int i = 0, j = (str.length() - 1); i < (str.length() / 2); i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    std::cout << '\n';
    std::cout << "Palindrome: " << str << " ";
    std::cout << '\n';
    return true;
}

std::string Is_Palindrome::remove_stuff(std::string &s)
{
    std::string str;
    for (unsigned int j = 0; j < s.length();)//заполняем пропуская ненужные элементы
    {
        if (is_capitalized(s[j]) == 0 && is_lower(s[j]) == 0 && s[j] != ' ')
        {
            j++;
        }
        else
        {
            str += s[j];
            j++;
        }
    }
    for (unsigned int i = 0; i < str.length(); i++)
    {
        std::cout << str[i] << " ";
    }
    std::cout << "\n";
    s = str;
    return str;
}

void Is_Palindrome::to_lower(std::string &s)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'a' + (s[i] - 'A');
        }
    }
}
bool Is_Palindrome::is_capitalized(const char &token)
{
    if (token >= 'A' && token <= 'Z')
    {
        return 1;
    }
    return 0;
}
bool Is_Palindrome::is_lower(const char &token)
{
    if (token >= 'a' && token <= 'z')
    {
        return 1;
    }
    return 0;
}
