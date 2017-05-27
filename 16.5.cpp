#include<iostream>

using std::cin;
using std::cout;
using std::endl;

template <class T> int com(const T&,const T&);

int main()
{
    int a=5;int b=7;
    cout<<com(a,b)<<endl;
    return 0;
}

template <class T> int com(const T& t1,const T& t2)
{
    if(t1>t2)
        return 1;
    if(t1<t2)
        return -1;
    else
        return 0;
}
