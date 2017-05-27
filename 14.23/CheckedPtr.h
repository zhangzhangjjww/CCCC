#ifndef CHECKEDPTR_H_INCLUDED
#define CHECKEDPTR_H_INCLUDED
#include<iostream>
#include<stdexcept>
#include<cctype>
class CheckedPtr
{
public:
    CheckedPtr(int* b,int* e):beg(b),end(e),curr(b) {}
    CheckedPtr& operator++();
    CheckedPtr& operator--();
    CheckedPtr operator++(int);
    CheckedPtr operator--(int);
    int& operator[](size_t index);
    int& operator*();
    const int& operator[](size_t index) const ;
    const int& operator*() const;
    bool operator==(const CheckedPtr&) const;
    bool operator>=(const CheckedPtr&) const;
    bool operator<=(const CheckedPtr&) const;
    bool operator!=(const CheckedPtr&) const;
    bool operator>(const CheckedPtr&) const;
    bool operator<(const CheckedPtr&) const;
    int* operator+(size_t index);
    int* operator-(size_t index);
private:
    int* beg;
    int* end;
    int* curr;
};


#endif // CHECKEDPTR_H_INCLUDED
