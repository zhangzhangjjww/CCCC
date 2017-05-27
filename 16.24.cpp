#include<iostream>
#include<cstring>
#include<string>
using namespace std;

template <class T1,class T2,class T3> T1 compare(T2,T3);

int main()
{
    short a=3;int b=2;
    char* c1="zdfgdh";char* c2="sdrghth";
    int re2=compare<int>(string(c1),string(c2));
    cout<<re2<<endl;
    int re=compare<int>(a,b);
    cout<<re<<endl;
    return 0;
}

template <class T1,class T2,class T3> T1 compare(T2 t2,T3 t3)
{
    if(t2<t3)
        return -1;
    if(t2>t3)
        return 1;
    else
        return 0;
}
