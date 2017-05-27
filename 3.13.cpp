#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ss;vector<int> result;
    int a;
    cout<<"Enter number:\n";
    while(cin>>a)
        ss.push_back(a);
    if(ss.size()%2==1)
    {
        for(vector<int>::size_type i=0;i!=(ss.size()-1)/2;i++)
            result.push_back(ss[i]+ss[ss.size()-1-i]);
        cout<<"result:\n";
        result.push_back(ss[(ss.size()-1)/2]);
        cout<<"The middle one don't add\n";
        for(vector<int>::size_type j=0;j!=result.size();j++)
        {

            cout<<result[j]<<" ";
            if(j%5==4)
                cout<<endl;
        }
    }
    if(ss.size()%2==0)
    {
        for(vector<int>::size_type i=0;i!=ss.size()/2;i++)
            result.push_back(ss[i]+ss[ss.size()-1-i]);
        cout<<"result:\n";
        for(vector<int>::size_type j=0;j!=result.size();j++)
        {

            cout<<result[j]<<" ";
            if(j%5==4)
                cout<<endl;
        }
    }

    return 0;
}
