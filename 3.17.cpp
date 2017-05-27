#include<iostream>
#include<vector>
#include<string>
#include<cctype>
int main()
{
    using namespace std;
    vector<string> v;
    string s;
    cout<<"Please enter a string(q to quit:)\n";
    while(cin>>s&&s!="q")
    {
        v.push_back(s);
    }
    int coun=0;
    for(decltype(v.size())i=0;i!=v.size();i++)
    {
        for(string::size_type j=0;j!=v[i].size();j++)
        {
            if(isalpha(v[i][j]))
                v[i][j]=toupper(v[i][j]);
        }
         coun++;
         cout<<v[i]<<"  ";
         if(coun%8==0)
                cout<<endl;
    }
    return 0;
}
