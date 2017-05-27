#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    string s;
    vector<string> v;
    cout<<"Please enter word:\n";
    while(cin>>s)
        v.push_back(s);
    for(vector<string>::iterator i=v.begin();i!=v.end();i++)
    {
        for(string::size_type j=0;j!=(*i).size();j++)
        {
            (*i)[j]=toupper((*i)[j]);
        }
    }
    int c=0;
    cout<<"Result:\n";
    for(vector<string>::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";

        if(c%8==7)
            cout<<endl;
        c++;
    }
    cout<<endl;
    return 0;
}
