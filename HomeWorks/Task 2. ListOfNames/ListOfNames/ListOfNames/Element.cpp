#include "Element.h"

Element::Element(std::string data):
    data(data)
{
}

Element::~Element()
{
}

Element* Element::GetPrev()
{
    return prev;
}

void Element::SetPrev(Element* elem)
{
    prev = elem;
}

Element* Element::GetNext()
{
    return next;
}

void Element::SetNext(Element* elem)
{
    next = elem;
}

std::string Element::GetData()
{
    return data;
}
