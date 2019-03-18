#pragma once

#include "Element.h"

class List
{
private:
    Element *head{nullptr};
    unsigned int count{0};

    void Remove(Element *elem);
    bool Compare(Element *elem1, Element *elem2);
    void Swap(Element *elem1, Element *elem2);
public:
    List();
    ~List();

    bool Add(std::string data);
    Element *GetHead();
    unsigned int GetSize();
    void Sort();
    void Clear();
};
