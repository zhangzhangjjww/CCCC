#include"CheckoutRecord.h"


std::ostream& operator<<(std::ostream& os,const Date& d)
{
    os<<d.year<<"."<<d.month<<"."<<d.day<<"."<<d.time;
    return os;
}

std::istream& operator>>(std::istream& is,Date& d)
{
    is>>d.year>>d.month>>d.day>>d.time;
    if(!is)
       d=Date();
    return is;
}

Date& Date::operator=(const Date& d)
{
    year=d.year;
    month=d.month;
    day=d.day;
    time=d.time;
    return *this;
}
std::ostream& operator<<(std::ostream& os,const CheckoutRecord& c)
{
    os<<"Book_id:"<<c.book_id<<'\t'<<"title:"<<c.title<<'\t'<<"date_borrowed:"<<c.date_borrowed<<'\t'<<"date_due:"<<c.date_due<<
    '\t'<<"borrower:"<<c.borrower.first<<" "<<c.borrower.second<<'\t';
    os<<"Wait_list:"<<'\t';
    for(std::vector<std::pair<std::string,std::string>*>::const_iterator i=c.wait_list.begin();i!=c.wait_list.end();++i)
        os<<(*i)->first<<" "<<(*i)->second<<"\t";
    return os;
}


std::istream& operator>>(std::istream& is,CheckoutRecord& c)
{
    std::cout<<"Book_id:";is>>c.book_id;
    std::cout<<"title:";is>>c.title;
    std::cout<<"date,borrowed:";is>>c.date_borrowed;
    std::cout<<"date_due:";is>>c.date_due;
    std::cout<<"borrower:";is>>c.borrower.first>>c.borrower.second;
    if(!is)
    {
        c=CheckoutRecord();
        return is;
    }
    c.wait_list.clear();
    std::cout<<"wait_list:";
    while(is)
    {
        std::pair<std::string,std::string> *p=new std::pair<std::string,std::string>;
        is>>p->first>>p->second;
        if(p->first=="q")
            return is;
        if(!is)
        {
            c=CheckoutRecord();
            delete p;
            return is;
        }
        c.wait_list.push_back(p);
    }
    return is;
}

CheckoutRecord& CheckoutRecord::operator=(const CheckoutRecord& c)
{
    book_id=c.book_id;
    title=c.title;
    date_borrowed=c.date_borrowed;
    date_due=c.date_due;
    borrower.first=c.borrower.first;
    borrower.second=c.borrower.second;
    wait_list.clear();
    for(std::vector<std::pair<std::string,std::string>*>::const_iterator i=c.wait_list.begin();i!=c.wait_list.end();++i)
    {
        std::pair<std::string,std::string> *p=new std::pair<std::string,std::string>;
        p->first=(*i)->first;
        p->second=(*i)->second;
        wait_list.push_back(p);
    }
    return *this;
}

std::pair<std::string,std::string> CheckoutRecord::operator[](const size_t index)
{
    return *wait_list[index];
}
