#include<iostream>
#include<cstring>
#include"port.h"
Port::Port(const char * br,const char * st,int b)
{
    int len=strlen(br);
    brand=new char[len+1];
    strcpy(brand,br);
    strcpy(style,st);
    bottles=b;
}
Port::Port(const Port &p)
{
    int len=strlen(p.brand);
    brand=new char[len+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if(this==&p)
        return *this;
    int len=strlen(p.brand);
    delete [] brand;
    brand=new char[len+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
    return *this;
}
Port & Port::operator+=(int b)
{
    if(b<0)
    {
        std::cout<<"B can't be a negative.\n";
        return *this;
    }
    bottles=bottles+b;
    return *this;
}
Port & Port::operator-=(int b)
{
    if(b>bottles||b<0)
    {
        std::cout<<"You can't do it.\n";
        return *this;
    }
    bottles=bottles-b;
    return *this;
}
void Port::show() const
{
    using std::cout;
    cout<<"Brand:"<<brand<<'\n';
    cout<<"Kind:"<<style<<std::endl;
    cout<<"Bottles:"<<bottles<<std::endl;
}
std::ostream & operator<<(std::ostream & os,const Port & p)
{
    os<<p.brand<<','<<p.style<<','<<p.bottles<<std::endl;
    return os;
}

VintagePort::VintagePort():Port("none","vintage",0)
{
    nickname=new char[6];
    strcpy(nickname,"none");
    year=0;
}
VintagePort::VintagePort(const char * br,int b,const char * nn,int y):Port(br,"vintage",b)
{
    int len=strlen(nn);
    nickname=new char[len+1];
    strcpy(nickname,nn);
    year=y;
}
VintagePort::VintagePort(const VintagePort & vp):Port(vp)
{
    int len=strlen(vp.nickname);
    nickname=new char[len+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this==&vp)
        return *this;
    Port::operator=(vp);
    int len=strlen(vp.nickname);
    delete [] nickname;
    nickname=new char[len+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
    return *this;
}
void VintagePort::show() const
{
    Port::show();
    using std::cout;
    cout<<"Nickname:"<<nickname<<std::endl;
    cout<<"Year:"<<year<<std::endl;
}
std::ostream & operator<<(std::ostream & os,const VintagePort & vp)
{
    os<<(Port)vp;
    os<<vp.nickname<<','<<vp.year<<std::endl;
    return os;
}
