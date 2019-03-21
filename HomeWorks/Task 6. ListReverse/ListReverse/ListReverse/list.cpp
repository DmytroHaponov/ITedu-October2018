#include "list.h"

List::List()
{

}

void List::Add(int num)
{
    if(!head)
    {
        head = new Node(num);
    }
    else
    {
        Node* node = new Node(num);
        node->SetNext(head);
        head = node;
    }

    size++;
}

int List::GetSize()
{
    return size;
}

void List::Clear()
{
    while(head)
    {
        Node* node = head->GetNext();
        delete head;
        head = node;
        size--;
    }
}

void List::GenerateList(int n)
{
    for(int i{0}; i < n; ++i)
    {
        this->Add(i);
    }
}

void List::Reverse()
{
    Node* cur = head->GetNext();
    head->SetNext(nullptr);
    Node *old = head;
    while(cur)
    {
        Node *temp = cur->GetNext();
        cur->SetNext(old);
        old = cur;
        cur = temp;
    }
    head = old;
}

void List::Show()
{
    Node* cur = head;
    while(cur)
    {
        std::cout << cur->GetData() << " ";
        cur = cur->GetNext();
    }
    std::cout << std::endl;
}
