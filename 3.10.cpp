#include<string>
#include<cctype>
#include<iostream>

using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
    string s,s1;
    cin>>s;
    for(string::size_type i=0;i!=s.size();i++)
        if(!ispunct(s[i]))
        s1=s1+s[i];
        cout<<s1<<endl;
    return 0;
}
