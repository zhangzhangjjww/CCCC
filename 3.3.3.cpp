#include<iostream>
#include<vector>

int main()
{
    using namespace std;
    vector<int> a;
    for(int i=0;i!=15;i++)
        a.push_back(i);
    for(auto &c : a)
    {
        c*=c;
        cout<<c<<endl;
    }
    return 0;
}
