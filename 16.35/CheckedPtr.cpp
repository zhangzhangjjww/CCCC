#include"CheckedPtr.h"

template <class T> CheckedPtr<T>& CheckedPtr<T>::operator++()
{
    if(curr==end)
        throw std::out_of_range("out of range");
    ++curr;
    return *this;
}

template <class T> CheckedPtr<T>& CheckedPtr<T>::operator--()
{
    if(curr==beg)
        throw std::out_of_range("out of range");
    --curr;
    return *this;
}

template <class T> CheckedPtr<T> CheckedPtr<T>::operator++(int )
{
    CheckedPtr ret(*this);
    ++*this;
    return ret;
}

template <class T> CheckedPtr<T> CheckedPtr<T>::operator--(int)
{
    CheckedPtr ret(*this);
    --*this;
    return ret;
}


/*error: expected initializer before '<' token|
F:\ÕÅ½¨Íþ\c++\16.35\CheckedPtr.cpp|26|error: expected initializer before '<' token|*/

