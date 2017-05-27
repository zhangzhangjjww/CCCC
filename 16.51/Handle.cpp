#include"Handle.h"

template <class T> T& Handle<T>::operator*()
{
    if(ptr) return *ptr;
    throw std::runtime_error("unbound Handle");
}

template <class T> T* Handle<T>::operator->()
{
    if(ptr) return ptr;
    throw std::runtime_error("unbound Handle");
}

template <class T> const T& Handle<T>::operator*() const
{
    if(ptr) return *ptr;
    throw std::runtime_error("unbound Handle");
}

template <class T> const T* Handle<T>::operator->() const
{
    if(ptr) return ptr;
    throw std::runtime_error("unbound Handle");
}

template <class T> Handle<T>& Handle<T>::operator=(const Handle &h)
{
    ++*h.use;
    rem_ref();
    ptr=h.ptr;
    use=h.use;
    return *this;
}
