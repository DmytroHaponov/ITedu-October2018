#ifndef ADDHASH_H
#define ADDHASH_H
#include <iostream>

template <typename T>
class AddHash
{
private:
    T m_data;
    static size_t m_create_hash;
    size_t m_hash;
public:
    AddHash(const T data);
    size_t get_hash();
    T get_data();
};


#endif // ADDHASH_H
