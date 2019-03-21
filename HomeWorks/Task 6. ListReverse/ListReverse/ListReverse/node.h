#pragma once

class Node
{
private:
    int data;
    Node* next = nullptr;
public:
    Node(int data);
    ~Node();

    int GetData();

    void SetNext(Node* node);
    Node* GetNext();
};
