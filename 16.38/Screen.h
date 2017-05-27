#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include<string>
#include<iostream>


template <int hi,int wid>
class Screen
{
public:
    Screen():screen(hi*wid,'#'),cursor(0),height(hi),width(wid) {}
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }
private:
    std::string screen;
    std::string::size_type cursor;
    std::string::size_type height,width;
    void do_display(std::ostream& os) const {os<<screen;}
};



#endif // SCREEN_H_INCLUDED
