#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include<string>
#include<iostream>

class Screen
{
public:
    typedef std::string::size_type index;
private:
    std::string contents;
    index cursor;
    index height,width;
    void do_display(std::ostream& os) const {os<<contents;}
public:
    Screen(index h,index w,std::string c):contents(c),height(h),width(w) {}
    char get() const {return contents[cursor];}
    inline char get(index ht,index wd) const;
    index get_cursor() const;
    Screen& move(index r,index c);
    Screen& set(char);
    Screen& set(index,index,char);
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }
    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }
};


#endif // SCREEN_H_INCLUDED
