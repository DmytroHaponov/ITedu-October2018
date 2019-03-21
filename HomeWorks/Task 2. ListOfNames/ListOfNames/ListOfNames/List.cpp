#include "List.h"

List::List()
{
}

List::~List()
{
    Clear();
}

bool List::Add(std::string data)
{
    if (count == 4294967295)
    {
        return false;
    }

    Element *elem = new Element(data);

    if (!head)
    {
        head = elem;
    }
    else
    {
        elem->SetNext(head);
        head->SetPrev(elem);
        head = elem;
    }

    count++;

    return true;
}

void List::Remove(Element *elem)
{
    if ((elem->GetPrev()) != nullptr)
    {
        elem->GetPrev()->SetNext(elem->GetNext());
    }

    if ((elem->GetNext()) != nullptr)
    {
        elem->GetNext()->SetPrev(elem->GetPrev());
    }

    if (elem == head)
    {
        head = head->GetNext();
    }

    count--;

    delete elem;
}

Element* List::GetHead()
{
    return head;
}

unsigned int List::GetSize()
{
    return count;
}

bool List::Compare(Element *elem1, Element *elem2)
{
    Element *first = elem1;
    Element *second = elem2;

    int size = static_cast<int>(first->GetData().length());

    if (first->GetData().length() > second->GetData().length())
    {
        size = static_cast<int>(second->GetData().length());
    }

    for (int i{0}; i < size; ++i)
    {
        // If symbol equal
        if (first->GetData().at(i) == second->GetData().at(i))
        {
            continue;
        }
        // If symbol 1 less than 2 - than we don't need to change them
        else if (first->GetData().at(i) < second->GetData().at(i))
        {
            return false;
        }
        // If symbol 2 less than 1 - than we need to change them
        else
        {
            return true;
        }
    }

    // If string equal - than we don't need to change them
    return false;
}

void List::Swap(Element *elem1, Element *elem2)
{
    Element *tmp = new Element("");
    tmp->SetNext(elem1->GetNext());
    tmp->SetPrev(elem1->GetPrev());

    // If elem1 near elem2 in list
    if (elem1->GetNext() == elem2)
    {
        elem1->SetNext(elem2->GetNext());
        elem1->SetPrev(elem2);
        if (elem1->GetNext())
        {
            elem1->GetNext()->SetPrev(elem1);
        }

        elem2->SetNext(elem1);
        elem2->SetPrev(tmp->GetPrev());
        if (elem2->GetPrev())
        {
            elem2->GetPrev()->SetNext(elem2);
        }
    }
    // If elem1 not near elem2 in list
    else
    {
        elem1->SetNext(elem2->GetNext());
        elem1->SetPrev(elem2->GetPrev());
        if (elem1->GetPrev())
        {
            elem1->GetPrev()->SetNext(elem1);
        }
        if (elem1->GetNext())
        {
            elem1->GetNext()->SetPrev(elem1);
        }

        elem2->SetNext(tmp->GetNext());
        elem2->SetPrev(tmp->GetPrev());
        if (elem2->GetPrev())
        {
            elem2->GetPrev()->SetNext(elem2);
        }
        if (elem2->GetNext())
        {
            elem2->GetNext()->SetPrev(elem2);
        }
    }

    delete tmp;
}

void List::Sort()
{
    Element *cur = head;

    while (cur)
    {
        Element *temp_cur = cur->GetNext();
        while (temp_cur)
        {
            if (Compare(cur, temp_cur))
            {
                Swap(cur, temp_cur);
                if (cur == head)
                {
                    head = temp_cur;
                }
                Element *tmp = cur;
                cur = temp_cur;
                temp_cur = tmp;
            }
            else
            {
                temp_cur = temp_cur->GetNext();
            }
        }
        cur = cur->GetNext();
    }
}

void List::Clear()
{
    while (head)
    {
        Remove(head);
    }
}
