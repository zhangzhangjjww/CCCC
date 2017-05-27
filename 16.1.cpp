#include<iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T> T abs(const T&);

int main()
{
    int a=-3;double b=5;
    char c='e';
    int re1=abs(a);
    double re2=abs(b);
    char re3=abs(c);
    cout<<re1<<" "<<re2<<" "<<re3<<endl;
    return 0;
}

template <class T> T abs(const T& t)
{
    if(t>0)
        return t;
    else
        return -t;
}
