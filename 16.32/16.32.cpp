#include"Queue.h"
#include"Queue.cpp"
#include<vector>
using namespace std;

int main()
{
    Queue<int> q;
    cin>>q;
    q.push(2);
    cout<<q<<endl;
    vector<int> v(10,1);
    q.assign(v.begin(),v.end());
    cout<<q<<endl;
    return 0;
}
