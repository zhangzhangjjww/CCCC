#ifndef SCREENPTR_H_INCLUDED
#define SCREENPTR_H_INCLUDED

#include<iostream>
#include<cctype>
#include<string>

class Screen
{
public:
    typedef std::string::size_type index;
private:
    std::string contents;
    index cursor;
    index height,width;
    void do_display(std::ostream& os) const
    {
        os<<contents;
    }
public:
    char get() const {return contents[cursor];}
    char get(index ht,index wd) const;
    index get_cursor() const;
    Screen():contents(""),cursor(0),height(0),width(0) {}
    Screen& set(char);
    Screen& move(index r,index c);
    Screen& display(std::ostream &os);
    const Screen& display(std::ostream&) const;
    bool operator!=(const Screen& s) const
    {
        return (contents!=s.contents)||(cursor!=s.cursor)||(height!=s.height)||(width!=width);
    }
    bool operator<(const Screen& s) const
    {
        return contents<s.contents;
    }

};
class ScrPtr
{
    friend class ScreenPtr;
    Screen *sp;
    size_t use;
    ScrPtr(Screen* p):sp(p),use(1) {}
    ~ScrPtr() {delete sp;}
};

class ScreenPtr
{
public:
    ScreenPtr(Screen* p):ptr(new ScrPtr(p)) {}
    ScreenPtr(const ScreenPtr& s):ptr(s.ptr) {++ptr->use;}
    ScreenPtr& operator=(const ScreenPtr& s);
    ~ScreenPtr() {if(--ptr->use==0) delete ptr;}
    bool operator==(const ScreenPtr& s);
    bool operator!=(const ScreenPtr& s);
private:
    ScrPtr *ptr;
};

class OwnScreenPtr
{
private:
    ScreenPtr* osp;
public:
    OwnScreenPtr(Screen *p):osp(new ScreenPtr(p)) {}
    ScreenPtr* operator->()
    {
        return osp;
    }
};
#endif // SCREENPTR_H_INCLUDED
