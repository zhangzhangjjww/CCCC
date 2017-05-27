#include<iostream>
#include<cctype>

template <class T> size_t sz(T&);
template <class T,size_t N> void array_init(T (&p)[N]);
using namespace std;

int main()
{
    int a[]={1,2,3,4,5,6};
    double b[]={1.2,2.3,3.3,45.6};
    cout<<sz(a)<<endl;
    array_init(a);
    array_init(b);
    return 0;
}

template <class T> size_t sz(T &t)
{
    return sizeof(t)/sizeof(t[0]);
}

template <class T,size_t N> void array_init(T (&p)[N])
{
    for(size_t i=0;i!=N;++i)
        cout<<p[i]<<endl;
}
