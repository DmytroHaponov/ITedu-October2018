#ifndef REVERSELIST_H
#define REVERSELIST_H
#include <iostream>

struct Node{
    int data;
    Node *link;
    Node(int i_data){
        this->data = i_data;
        link = nullptr;
    }
};

struct SingleLinkedList{

    Node *head = nullptr;

    void reverse(){

        Node *prev, *curr, *next;
        prev = nullptr;
        next = nullptr;
        curr = head;

        while(curr != nullptr){
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
   }

    void print(){

        struct Node *temp = head;

        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->link;
        }
    }

    void push(int i_data){

        Node *temp = new Node(i_data);
        temp->link = head;
        head = temp;
    }
};



#endif // REVERSELIST_H
