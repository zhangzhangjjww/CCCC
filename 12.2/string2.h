#ifndef STRING2_H_INCLUDED
#define STRING2_H_INCLUDED
#include<iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int cinlim=80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length() const {return len;}
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    String operator+(const String & s) const;
    String operator+(const char * s) const;
    void stringlow();
    void stringup();
    int has(const char s) const;
    friend String operator+(const char * s,const String &st);
    friend bool operator<(const String &st1,const String & st2);
    friend bool operator>(const String &st1,const String & st2);
    friend bool operator==(const String &st1,const String & st2);
    friend ostream & operator<<(ostream & os,const String &st);
    friend istream & operator>>(istream & os,String & st);
    static int howmany();
};


#endif // STRING2_H_INCLUDED
