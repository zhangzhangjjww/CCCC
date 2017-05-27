#include<iostream>
#include<vector>
#include<string>
#include<cctype>
int main()
{
    using namespace std;
    vector<string> v;int cu=0;
    cout<<"Enter a string(q to quit):\n";
    string s;
    while(cin>>s&&s!="q")
    {
        v.push_back(s);
    }
    string nll;
    cin.get();
    getline(cin,nll);

    v.push_back(nll);
    v.push_back("ss");
    vector<string>::iterator i;
    for(i=v.begin();i!=v.end()&&!i->empty();i++)

{

       for(auto k=(*i).begin();k!=(*i).end();k++)
        if(isalpha(*k))
        (*k)=toupper(*k);
        cu++;}
        for(int k=cu-1;k!=-1;k--)
            cout<<v[k]<<" ";

    return 0;


}
