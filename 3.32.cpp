#include<iostream>
#include<vector>
int main()
{
    using namespace std;
    int a1[10];int a2[10];
    vector<int> v1,v2;
    for(int i=0;i!=10;i++)
    {
        a1[i]=i;
        v1.push_back(i);
        a2[i]=a1[i];
    }
    v2=v1;
    for(int i=0;i!=10;i++)
    {
        cout<<a1[i]<<endl;
        cout<<a2[i]<<endl;
        cout<<v1[i]<<endl;
        cout<<v2[i]<<endl;
    }
    return 0;
}
