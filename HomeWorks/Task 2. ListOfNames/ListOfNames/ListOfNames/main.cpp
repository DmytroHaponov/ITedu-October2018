#include <fstream>
#include <iostream>

#include "List.h"

static int namesCount{50};

// Create file with random Names with length from 4 to 8 symbols
void CreateFile(std::string filename)
{
    std::fstream file;
    file.open(filename, std::ios::out);
    for (int i{0}; i < namesCount; ++i)
    {
        std::string name;
        int len{rand() % 4 + 4};
        for (int j{0}; j < len; ++j)
        {
            name += static_cast<char>((rand() % 25 + 65));
        }

        file << name << '\n';
    }
    file.close();
}

// Read names from file and push them into list
void LoadNamesFromFile(std::string filename, List *list)
{
    std::fstream file;
    file.open(filename, std::ios::in);

    char symb{'\0'};
    std::string name;
    while (file >> std::noskipws >> symb)
    {
        if (symb == '\n')
        {
            list->Add(name);
            name.clear();
        }
        else
        {
            name += symb;
        }
    }

    file.close();
}

// Create file and write names into it
void SaveNames(std::string filename, List *list)
{
    std::fstream file;
    file.open(filename, std::ios::out);

    Element *cur{list->GetHead()};
    while (cur)
    {
        file << cur->GetData() << '\n';
        cur = cur->GetNext();
    }

    file.close();
}

int main()
{
    // You can comment this part for run in mode "50 words"
    std::cin >> namesCount;
    if(namesCount > 5000)
    {
        std::cout << "Are you crazy?) Sorting will be very long" << std::endl;
        return 0;
    }

    CreateFile("../source.txt");

    List *list = new List();
    LoadNamesFromFile("../source.txt", list);

    list->Sort();

    SaveNames("../destination.txt", list);

    delete list;

    return 0;
}
