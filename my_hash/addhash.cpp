#include "addhash.h"

template <typename T>
AddHash<T>::AddHash(const T data)
{
    m_data = data;
    m_hash = m_create_hash++;
}
template <typename T>
size_t AddHash<T>::get_hash()
{
    return m_hash;
}
template <typename T>
T AddHash<T>::get_data()
{
    return m_data;
}

template <typename T>
size_t AddHash<T>::m_create_hash = 0;
