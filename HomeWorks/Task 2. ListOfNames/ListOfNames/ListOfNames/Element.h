#pragma once

#include <string>

class Element
{
private:
    Element *prev{nullptr};
    Element *next{nullptr};
    std::string data;
public:
    Element(std::string data);
    ~Element();

    Element* GetPrev();
    void SetPrev(Element* elem);

    Element* GetNext();
    void SetNext(Element* elem);

    std::string GetData();
};
