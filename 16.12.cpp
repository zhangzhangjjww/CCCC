#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

template <class T1,class T2> T2 find(T1,T1,T2);

int main()
{
    vector<string> v;
    string s;
    while(cin>>s&&s!="q")
        v.push_back(s);
    string re=find(v.begin(),v.end(),s);
    cout<<re<<endl;
    return 0;
}

template <class T1,class T2> T2 find(T1 t11,T1 t12,T2 a)
{
    T1 tt=t11;
    map<T2,int> m;
    while(tt!=t12)
    {
        ++m[*tt];
        ++tt;
    }
    int cou=0;T2 ss;
    for(typename map<T2,int>::iterator i=m.begin();i!=m.end();++i)
    {
        if(i->second>cou)
        {
            cou=i->second;
            ss=i->first;
        }
    }
    return ss;
}
