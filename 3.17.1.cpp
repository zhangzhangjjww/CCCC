#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int n;int c=0;
    vector<int> v,re;
    cout<<"please enter number:\n";
    while(cin>>n)
        v.push_back(n);

    if(v.size()%2==1)
    {
        vector<int>::iterator j=v.end()-1;
        for(vector<int>::iterator i=v.begin();i<j;i++,j--)
            re.push_back(*i+*(j));
        re.push_back(*j);
        cout<<"Result:\n";
        cout<<"The middle one don't add\n";
        for(vector<int>::iterator i=re.begin();i!=re.end();i++)
        {
            c++;
            cout<<*i<<" ";
            if(c%8==7)
                cout<<endl;
        }

    }
    if(v.size()%2==0)
    {
        for(vector<int>::iterator i=v.begin(),j=v.end()-1;i<j;i++,j--)
            re.push_back(*i+*j);
        cout<<"Result:\n";
        for(vector<int>::iterator i=re.begin();i!=re.end();i++)
        {
            c++;
            cout<<*i<<" ";
            if(c%8==7)
                cout<<endl;
        }
    }
    cout<<endl;
    return 0;


}
