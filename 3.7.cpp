#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1,s2;
    cout<<"Please enter two string:\n";
    cin>>s1;cin>>s2;
    if(s1.size()==s2.size())
        cout<<s1<<" equal to "<<s2<<endl;
    if(s1.size()>s2.size())
        cout<<s1<<" large than "<<s2<<endl;
    if(s1.size()<s2.size())
        cout<<s1<<" small than "<<s2<<endl;
    return 0;
}
