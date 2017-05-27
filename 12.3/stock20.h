#ifndef STOCK20_H_INCLUDED
#define STOCK20_H_INCLUDED
#include<iostream>
class Stock
{
private:
    char * s;
    int len;
    int shares;
    double share_val;
    double total_val;
    void set_tot() {total_val=shares*share_val;}
public:
    Stock();
    Stock(const char * p,long n=0,double pr=0);
    Stock(const Stock & t);
    ~Stock();
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    const Stock & topval(const Stock & s) const;
    Stock operator=(const Stock & t);
    friend  std::ostream & operator<<(std::ostream & os,const Stock & t);
};


#endif // STOCK20_H_INCLUDED
