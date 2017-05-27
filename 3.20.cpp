#include<iostream>
#include<vector>

int main()
{
    using namespace std;
    vector<int> v;
    for(decltype(v.size())i=0;i!=10;i++)
        v.push_back(i);
    for(vector<int>::size_type i=0,j=v.size()-1;i!=v.size()/2+1;i++,j--)
        cout<<v[i]+v[j]<<endl;
    return 0;
}
