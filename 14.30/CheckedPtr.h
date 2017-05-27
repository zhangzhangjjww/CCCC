#ifndef CHECKEDPTR_H_INCLUDED
#define CHECKEDPTR_H_INCLUDED
#include<iostream>
#include<stdexcept>
#include<cctype>
#include"ScreenPtr.h"
class CheckedPtr
{
public:
    CheckedPtr(Screen* b,Screen* e):beg(b),end(e),curr(b) {}
    CheckedPtr& operator++();
    CheckedPtr& operator--();
    CheckedPtr operator++(int);
    CheckedPtr operator--(int);
    Screen& operator[](size_t index);
    Screen& operator*();
    const Screen& operator[](size_t index) const ;
    const Screen& operator*() const;
    bool operator==(const CheckedPtr&) const;
    bool operator>=(const CheckedPtr&) const;
    bool operator<=(const CheckedPtr&) const;
    bool operator!=(const CheckedPtr&) const;
    bool operator>(const CheckedPtr&) const;
    bool operator<(const CheckedPtr&) const;
    Screen* operator+(size_t index);
    Screen* operator-(size_t index);
    Screen* operator->() {return curr;}
private:
    Screen* beg;
    Screen* end;
    Screen* curr;
};


#endif // CHECKEDPTR_H_INCLUDED
