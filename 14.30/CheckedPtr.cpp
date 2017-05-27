#include"CheckedPtr.h"
#include"ScreenPtr.h"

CheckedPtr& CheckedPtr::operator++()
{
    if(curr==end)
        throw std::out_of_range("increment past the end of CheckedPtr");
    ++curr;
    return *this;
}
CheckedPtr& CheckedPtr::operator--()
{
    if(curr==beg)
        throw std::out_of_range("decremet past the beginning of CheckedPtr");
    --curr;
    return *this;
}

CheckedPtr CheckedPtr::operator++(int)
{
    CheckedPtr ret(*this);
    ++*this;
    return ret;
}

CheckedPtr CheckedPtr::operator--(int)
{
    CheckedPtr ret(*this);
    --*this;
    return ret;
}

Screen& CheckedPtr::operator[](size_t index)
{
    if((beg+index)>end||(index+beg)<beg)
        throw std::out_of_range("out of range");
    return *(beg+index);
}
Screen& CheckedPtr::operator*()
{
    if(curr==end)
        throw std::out_of_range("out of range");
    return *curr;
}
const Screen& CheckedPtr::operator[](size_t index) const
{
    if((beg+index)>end||(index+beg)<beg)
        throw std::out_of_range("out of range");
    return *(beg+index);
}
const Screen& CheckedPtr::operator*() const
{
    if(curr==end)
        throw std::out_of_range("out of range");
    return *curr;
}

bool CheckedPtr::operator==(const CheckedPtr& c) const
{
    Screen* temp1,*temp2;
    for(temp1=beg,temp2=c.beg;temp1!=end&&temp2!=c.end;++temp1,++temp2)
    {
        if(*temp1!=*temp2)
            return false;
    }
    if((c.end-c.beg)!=(end-beg))
        return false;
    return true;

}
bool CheckedPtr::operator!=(const CheckedPtr& c) const
{
    return !(*this==c);
}

bool CheckedPtr::operator<(const CheckedPtr& c) const
{
    if(*this!=c)
    {
        size_t sz=(end-beg)>(c.end-c.beg)?(c.end-c.beg):(end-beg);
        Screen* temp1=beg,*temp2=c.beg;
        for(size_t i=0;i!=sz;++i)
        {
            if(*temp1<*temp2)
                return true;
            temp1++;temp2++;
        }
        if((end-beg)<(c.end-c.beg))
            return true;
        else
            return false;
    }
    else
        return false;
}
bool CheckedPtr::operator>(const CheckedPtr& c) const
{
    if(*this!=c&&(!(*this<c)))
        return true;
    else
        return false;
}
bool CheckedPtr::operator<=(const CheckedPtr& c) const
{
    return (*this==c)||(*this<c);
}
bool CheckedPtr::operator>=(const CheckedPtr& c) const
{
    return (*this==c)||(*this>c);
}

Screen* CheckedPtr::operator+(size_t index)
{
    if((curr+index)>beg)
        throw std::out_of_range("out of range");
    else
        curr=curr+index;
    return curr;
}

Screen* CheckedPtr::operator-(size_t index)
{
    if((curr-index)<beg)
        throw std::out_of_range("out of range");
    else
        curr-=index;
    return curr;
}
