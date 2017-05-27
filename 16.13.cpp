#include<iostream>
#include<vector>
#include<list>

using namespace std;

template <class T> void out(const T&);
template <class T> void out2(const T&);

int main()
{
    vector<int> v;list<int> l;
    for(vector<int>::size_type i=0;i!=10;++i)
        v.push_back(i);
    for(list<int>::size_type i=0;i!=10;++i)
        l.push_back(i);
    out2(v);
    out2(l);
    return 0;
}

template <class T> void out(const T& t)
{
    for(typename T::size_type i=0;i!=t.size();++i)
        cout<<i<<endl;
}

template <class T> void out2(const T &t)
{
    for(typename T::const_iterator i=t.begin();i!=t.end();++i)
        cout<<*i<<endl;
}
