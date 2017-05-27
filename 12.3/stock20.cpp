#include<iostream>
#include<cstring>
#include"stock20.h"
Stock::Stock()
{
    len=strlen("no name");
    s=new char[len+1];
    strcpy(s,"no name");
    shares=0;
    share_val=0;
    total_val=0;
}
Stock::Stock(const char *p,long n,double pr)
{
    len=strlen(p);
    s=new char[len+1];
    strcpy(s,p);
    if(n<0)
    {
        std::cout<<"Number of shares can't be negative;"<<s<<" shares set to 0.\n";
        shares=0;
    }
    else
        shares=n;
    share_val=pr;
    set_tot();
}
Stock::Stock(const Stock & t)
{
    len=t.len;
    s=new char[len+1];
    strcpy(s,t.s);
    shares=t.shares;
    share_val=t.share_val;
    total_val=t.total_val;
}
Stock::~Stock()
{
    delete [] s;
    std::cout<<"done\n";
}
void Stock::buy(long num,double price)
{
    if(num<0)
    {
        std::cout<<"Number of shares purchased can't be negative."<<"Transaction ia aborted.\n";
    }
    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}
void Stock::sell(long num,double price)
{
    using std::cout;
    if(num<0)
    {
        cout<<"Number of shares sold can't be negative."<<"transaction is abotred.\n";
    }
    else
        if(num>shares)
    {
        cout<<"You can't sell more than you have! "<<"Transanction is abotred.\n";
    }
    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val=price;
    set_tot();
}
const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val>total_val)
        return s;
    else
        return *this;
}
Stock Stock::operator=(const Stock & t)
{
    len=t.len;
    delete [] s;
    s=new char[len+1];
    strcpy(s,t.s);
    shares=t.shares;
    share_val=t.share_val;
    total_val=t.total_val;
    return *this;
}
std::ostream & operator<<(std::ostream & os,const Stock & t)
{
    using std::ios_base;
    ios_base::fmtflags orig=os.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec=os.precision(3);
    os<<"Company:"<<t.s<<" Shares:"<<t.shares<<std::endl;
    os<<"  Share Price:$"<<t.share_val;
    os.precision(2);
    os<<" Total Worth:$"<<t.total_val<<std::endl;
    os.setf(orig,ios_base::floatfield);
    os.precision(prec);
    return os;
}
