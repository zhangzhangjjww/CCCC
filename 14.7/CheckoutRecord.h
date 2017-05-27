#ifndef CHECKOUTRECORD_H_INCLUDED
#define CHECKOUTRECORD_H_INCLUDED
#include<utility>
#include<vector>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<iostream>
#include<cctype>
class Date
{
private:
    std::string year;
    std::string month;
    std::string day;
    std::string time;
public:
    Date():year(""),month(""),day(""),time("") {}
    Date(const std::string& y,const std::string& m,const std::string& d,const std::string &t):
        year(y),month(m),day(d),time(t) {}
    Date& operator=(const Date& d);
    friend std::ostream& operator<<(std::ostream& os,const Date& d);
    friend std::istream& operator>>(std::istream& is,Date & d);

};

class CheckoutRecord
{
private:
    double book_id;
    std::string title;
    Date date_borrowed;
    Date date_due;
    std::pair<std::string,std::string> borrower;
    std::vector<std::pair<std::string,std::string>*> wait_list;
public:
    CheckoutRecord():book_id(0),title(""),date_borrowed(),date_due(),borrower("","") {}
    CheckoutRecord(double id,std::string& ti,Date& da_bo,Date& da_du,std::pair<std::string,std::string>& bo,std::vector<std::pair<std::string,std::string>*>& wa):
        book_id(id),title(ti),date_borrowed(da_bo),date_due(da_du),borrower(bo),wait_list(wa) {};
    CheckoutRecord& operator=(const CheckoutRecord& c);
    std::pair<std::string,std::string> operator[](const size_t index);
    friend std::ostream& operator<<(std::ostream& os,const CheckoutRecord& c);
    friend std::istream& operator>>(std::istream& is,CheckoutRecord& c);

};

#endif // CHECKOUTRECORD_H_INCLUDED
