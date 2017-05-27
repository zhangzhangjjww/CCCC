#ifndef CHECKEDPTR_H_INCLUDED
#define CHECKEDPTR_H_INCLUDED
#include<cctype>
#include<stdexcept>

template <class T> class CheckedPtr
{
public:
    CheckedPtr(T *b,T *e):beg(b),end(e),curr(b) {}
    CheckedPtr& operator++();
    CheckedPtr& operator--();
    CheckedPtr operator++(int);
    CheckedPtr operator--(int);
    T& operator[](size_t index);
    T& operator*();
    const T& operator[](size_t index) const;
    const T& operator*() const;
private:
    T* beg;
    T* end;
    T* curr;
};


#endif // CHECKEDPTR_H_INCLUDED
