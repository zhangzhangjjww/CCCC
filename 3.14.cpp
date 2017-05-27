#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<string> v1;
    string s;
    cout<<"Please enter word:\n";
    while(cin>>s)
        v1.push_back(s);
    for(vector<string>::size_type i=0;i!=v1.size();i++)
    {
        for(string::size_type j=0;j!=v1[i].size();j++)
            v1[i][j]=toupper(v1[i][j]);
    }
    cout<<" result:\n";
    for(vector<string>::size_type i=0;i!=v1.size();i++)
    {
        cout<<v1[i]<<" ";
        if(i%8==7)
            cout<<endl;
    }

    return 0;
}
