#include<iostream>
#include<string>

using std::cin;
using std::endl;
using std::string;
using std::cout;

int main()
{
    string s1,s2;
    while(cin>>s1)
        s2=s2+" "+s1;
    cout<<s2<<endl;
    return 0;
}
