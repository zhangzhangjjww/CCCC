#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v(10);
    int n;
    cout<<"Please enter 10 numbers:\n";
    for(vector<int>::iterator i=v.begin();i!=v.end();i++)
    {
        cin>>n;
        *i=n*2;
    }
    cout<<"Result:\n";
    for(vector<int>::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
