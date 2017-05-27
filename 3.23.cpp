#include<iostream>
#include<vector>

int main()
{
    using namespace std;
    vector<int> v(10,1);
    for(auto i=v.begin();i!=v.end();i++)
    {
        *i=(*i)*2;
        cout<<*i<<endl;
    }
}
