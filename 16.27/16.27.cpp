#include"find.h"

int main()
{
    vector<int> v;int n;
    while(cin>>n&&n!=0)
        v.push_back(n);
    int re=middle(v);
    cout<<re<<endl;
    return 0;
}
