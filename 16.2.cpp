#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<ostream>
using namespace std;

template <class T> void output(ostream&,const T&);

int main()
{
    string s("sdgdfgghfghfj");
    output(cout,s);output(cout,12);output(cout,"dsfd");
    output(cout,12.33);
    ofstream os("zzz.txt");
    output(os,s);
    stringstream ss;
    output(ss,s);
    string s2;
    ss>>s2;
    cout<<s2<<endl;
    return 0;
}

template <class T> void output(ostream& os,const T& t)
{
    os<<t<<endl;
}
