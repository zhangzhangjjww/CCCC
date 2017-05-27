#include<iostream>
#include<string>
#include<cstring>
int main()
{
    using namespace std;
    string s1="sdffgdfhh";
    string s2="segsgg";
    if(s1>s2)
        cout<<"s1"<<endl;
    else
        if(s1<s2)
        cout<<"s2"<<endl;
    else
        cout<<"s2 s1"<<endl;
    char c1[]="sfrwewerg";
    char c2[]="sdgfht";
    int c=strcmp(c1,c2);
    if(c1==0)
        cout<<"a1 a2"<<endl;
    else
        if(c>0)
        cout<<"a1"<<endl;
    else
        cout<<"a2"<<endl;
    char c3[100]=" ";
    strcpy(c3,c1);
    for(auto i:c3)
        cout<<i;
    cout<<endl;
    strcat(c3,c2);
    for(auto i:c3)
        cout<<i;
    cout<<endl;
    return 0;
}
