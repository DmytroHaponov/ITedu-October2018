#pragma once

#include <iostream>

#include "node.h"

class List
{
private:
    Node* head = nullptr;
    int size = 0;
public:
    List();

    void Add(int num);
    int GetSize();
    void Clear();
    void GenerateList(int n);
    void Reverse();
    void Show();
};
