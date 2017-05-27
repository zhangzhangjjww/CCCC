#ifndef HASPTR_H_INCLUDED
#define HASPTR_H_INCLUDED
#include<cctype>


class U_Ptr
{
    friend class HasPtr;
    int *ip;
    size_t use;
    U_ptr(int* p):ip(p),use(1) {}
    ~U_ptr() {delete ip;}
};

class HasPtr
{
public:
    HasPtr(int* p,int i):ptr(new U_Ptr(p)),val(i) {}
    HasPtr(const HasPtr &o):ptr(o.ptr),val(o.val) {++ptr->use;}
    HasPtr& operator=(const HasPrt & o);
    ~HasPtr() {if(--ptr->use==0) delete ptr;}
private:
    U_Ptr *ptr;
    int val;
};

Has_Ptr& HasPtr::operator=(const HasPtr &o)
{
    ++o.ptr->use;
    if(--ptr->use==0)
        delete ptr;
    ptr=o.ptr;
    val=o.val;
    return *this;
}

#endif // HASPTR_H_INCLUDED
