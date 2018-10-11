#ifndef HEADER_H
#define HEADER_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include<string.h>

void write_in_file(char **names, int words_number);

int hash (char **names,int number_words);

void read_from_file(char **names, int words_number, char string[]);//, std::string);

int generate_file(char *name);

bool compare (char array1[], char array2[]);

int is_in (char n, char alphab[], char alphab_cap[]);

void assign_string(char array1[], char tobeassigned[]);

void sort(char **array,const int &number_of_elements);

char** gen_2d_array(int words_number);

#endif // HEADER_H
