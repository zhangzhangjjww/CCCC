#include<string>
#include"Screen.h"

using std::string;

char Screen::get(index r,index c) const
{
    index row=r*width;
    return contents[row+c];
}

inline Screen::index Screen::get_cursor() const
{
    return cursor;
}

Screen& Screen::set(char c)
{
    contents[cursor]=c;
    return *this;
}

Screen& Screen::set(index r,index c,char ch)
{
    index row=width*r;
    contents[row+c]=ch;
    return *this;
}
Screen& Screen::move(index r,index c)
{
    index row=r*width;
    cursor=row+c;
    return *this;
}
