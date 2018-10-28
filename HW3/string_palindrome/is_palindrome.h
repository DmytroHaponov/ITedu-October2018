#ifndef IS_PALINDROME_H
#define IS_PALINDROME_H
#include<iostream>
#include <string.h>
class Is_Palindrome
{
public:
    bool is_capitalized(const char &token);
    bool is_lower(const char &token);
    bool operator()(std::string &s);
    void to_lower(std::string &s);
    std::string remove_stuff(std::string &s);
    bool is_palindrome(std::string &str);
    //void split_n_check(std::string &str, std::vector<int> &vec);
    //bool is_palindrome(std::string &str);
    //bool is_in(const std::vector<unsigned int> &vec, unsigned int i);
};
#endif // IS_PALINDROME_H
