#ifndef SALES_ITEM_H_INCLUDED
#define SALES_ITEM_H_INCLUDED
#include<iostream>
#include<string>

class Sales_item
{
private:
    std::string isbn;
    unsigned units_sold;
    double revenue;
public:
    Sales_item():units_sold(0),revenue(0) {}
    Sales_item(std::string i,unsigned u,double r):isbn(i),units_sold(u),revenue(r) {}
    Sales_item(const Sales_item& s):isbn(s.isbn),units_sold(s.units_sold),revenue(s.revenue) {}
    bool same_isbn(const Sales_item& s) const
    {
        return isbn==s.isbn;
    }
    double avg_price() const;
    Sales_item& operator+=(const Sales_item & s);
    Sales_item& operator=(const Sales_item &s);
    friend Sales_item operator+(const Sales_item& s1,const Sales_item& s2);
    operator std::string() const {return isbn;}
    operator double() const {return revenue;}
};


#endif // SALES_ITEM_H_INCLUDED
