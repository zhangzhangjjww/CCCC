#include<iostream>
#include<vector>
#include<string>

using namespace std;

template <class T1,class T2> int count(T1,T2);
template <> int count<vector<string>,string>(vector<string>,string);
int main()
{
    vector<int> v;
    for(vector<int>::size_type i=0;i!=10;++i)
    {v.push_back(i);v.push_back(i+1);}
    int re=count(v,2);
    cout<<re<<endl;
    vector<string> v2;
    string s;
    while(cin>>s&&s!="q")
        v2.push_back(s);
    int re2=count(v2,string("zjw"));
    cout<<re2<<endl;
    return 0;
}

template <class T1,class T2> int count(T1 t1,T2 t2)
{
    int re=0;
    for(typename T1::iterator i=t1.begin();i!=t1.end();++i)
        if(*i==t2)
        ++re;
    return re;
}
template <> int count<vector<string>,string>(vector<string> v,string s)
{
    cout<<"use now\n";
    int re=0;
    for(vector<string>::iterator i=v.begin();i!=v.end();++i)
        if(*i==s)
        ++re;
    return re;
}
