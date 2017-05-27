#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"please a number:";
    cin>>n;
    cout.setf(ios_base::showbase);
    cout.width(15);
    cout<<n;
    cout.width(15);
    cout<<hex<<n;
    cout.width(15);
    cout<<oct<<n;
    cout<<endl;
    cout<<dec;
    return 0;
}
