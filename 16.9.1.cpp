#include<iostream>
#include<vector>
#include<string>

using namespace std;

template <class T1,class T2> T1 find(T1,T1,T2&);

int main()
{
    vector<int> v1;
    for(vector<int>::size_type i=0;i!=10;++i)
        v1.push_back(i);
    int v=3;
    vector<int>::iterator i1=find(v1.begin(),v1.end(),v);
    if(i1!=v1.end())
        cout<<*i1<<endl;
    else
        cout<<"No.\n";
    vector<string> v2;
    string s;
    while(cin>>s&&s!="q")
        v2.push_back(s);
    string s2("zjw");
    vector<string>::iterator i2=find(v2.begin(),v2.end(),s2);
    if(i2!=v2.end())
        cout<<*i2<<endl;
    else
        cout<<"No.\n";
    return 0;
}

template <class T1,class T2> T1 find(T1  t11,T1  t12,T2 &t2)
{
    T1 tt=t11;
    while(tt!=t12)
    {
        if(*tt==t2)
            return tt;
        ++tt;
    }
    if(tt==t12)
        return tt;
}
