#include"ScreenPtr.h"

char Screen::get(index h,index w) const
{
    index row=h*width;
    return contents[row+w];
}

Screen::index Screen::get_cursor() const
{
    return cursor;
}
Screen& Screen::set(char c)
{
    contents[cursor]=c;
    return *this;
}
Screen& Screen::move(index r,index c)
{
    index row=r*width;
    cursor=row+c;
    return *this;
}
Screen& Screen::display(std::ostream& os)
{
    do_display(os);return *this;
}
const Screen& Screen::display(std::ostream& os) const
{
    do_display(os);return *this;
}

ScreenPtr& ScreenPtr::operator=(const ScreenPtr& s)
{
    if(&s!=this)
    {
        if(--ptr->use==0)
            delete ptr;
        ptr=s.ptr;
        ++ptr->use;
    }
    return *this;
}
bool ScreenPtr::operator!=(const ScreenPtr& s)
{
    if(ptr==s.ptr)
        return false;
    return true;
}
bool ScreenPtr::operator==(const ScreenPtr& s)
{
    return !(*this!=s);
}
