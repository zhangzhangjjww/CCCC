#include"Sales_item.h"

double Sales_item::avg_price() const
{
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_item operator+(const Sales_item& s1,const Sales_item& s2)
{
    Sales_item ex(s1);
    ex.units_sold+=s2.units_sold;
    ex.revenue+=s2.revenue;
    return ex;
}
Sales_item& Sales_item::operator+=(const Sales_item& s)
{
    *this=(*this)+s;
    return *this;
}

Sales_item& Sales_item::operator=(const Sales_item& s)
{
    isbn=s.isbn;
    return *this;
}
