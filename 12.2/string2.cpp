#include<cstring>
#include"string2.h"
#include<cctype>
#include<iostream>
using std::cin;
using std::cout;
int String::num_strings=0;
int String::howmany()
{
    return num_strings;
}
String::String(const char * s)
{
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    num_strings++;
}
String::String()
{
    len=4;
    str=new char[1];
    str[0]='\0';
    num_strings++;
}
String::String(const String & st)
{
    num_strings++;
    len=st.len;
    str=new char [len+1];
    std::strcpy(str,st.str);
}
String::~String()
{
    --num_strings;
    delete [] str;
}
String & String::operator=(const String &st)
{
    if(this==&st)
        return *this;
    delete []str;
    len=st.len;
    str=new char[len+1];
    std::strcpy(str,st.str);
    return *this;
}
String & String::operator=(const char * s)
{
    delete [] str;
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    return *this;
}
char & String::operator[](int i)
{
    return str[i];
}
const char & String::operator[](int i) const
{
    return str[i];
}
bool operator<(const String &st1,const String & st2)
{
    return(std::strcmp(st1.str,st2.str)<0);
}
bool operator>(const String &st1,const String & st2)
{
    return st2<st1;
}
bool operator==(const String &st1,const String & st2)
{
    return(std::strcmp(st1.str,st2.str)==0);
}
ostream & operator<<(ostream & os,const String & st)
{
    os<<st.str;
    return os;
}
istream & operator>>(istream & is,String &st)
{
    char temp[String::cinlim];
    is.get(temp,String::cinlim);
    if(is)
        st=temp;
    while(is&&is.get()!='\n')
        continue;
    return is;
}
String String::operator+(const String & s) const
{
    String sum;
    sum.len=len+s.len;
    delete [] sum.str;
    sum.str=new char[sum.len+1];
    std::strcat(sum.str,str);
    std::strcat(sum.str,s.str);
    return sum;
}
void String::stringlow()
{
    int i=0;
    while(str[i])
    {
        if(std::isalpha(str[i]))
            str[i]=tolower(str[i]);
            i++;
    }
}
void String::stringup()
{
    int i=0;
    while(str[i])
      {
          if(std::isalpha(str[i]))
        str[i]=toupper(str[i]);
        i++;}
}
int String::has(const char s) const
{
    int i=0;int j=0;
    while(str[i])
    {
        if(str[i]==s)
            j++;
        i++;
    }
    return j;

}
String String::operator+(const char * s) const
{
    String sum;
    sum.len=std::strlen(s)+len;
    delete [] sum.str;
    sum.str=new char[sum.len+2];
    std::strcat(sum.str,str);
    std::strcat(sum.str,s);
    return sum;
}
String operator+(const char * s,const String & st)
{
    String sum;
    sum.len=std::strlen(s)+st.len;
    delete [] sum.str;
    sum.str=new char[sum.len+1];
    std::strcat(sum.str,s);
    std::strcat(sum.str,st.str);
    return sum;
}
