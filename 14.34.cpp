#include<iostream>
#include<algorithm>
#include<string>
#include<vector>;

using namespace std;

class GT
{
private:
    string val;
public:
    GT(string s):val(s) {}
    bool operator()(string s)
    {
        return val==s;
    }
};
int main()
{
    string s;
    vector<string> v;
    while(cin>>s&&s!="q")
        v.push_back(s);
    string ss;
    cout<<"Enter a string:";
    cin>>ss;
    string sss="zzz";
    replace_if(v.begin(),v.end(),GT(ss),sss);
    for(vector<string>::iterator i=v.begin();i!=v.end();++i)
        cout<<*i<<endl;
    return 0;
}
