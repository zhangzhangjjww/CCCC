#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout<<"Enter your name:";
    string st;
    cin>>st;
    cout<<"Enter your hourly wages:";
    int wa;cin>>wa;
    cout<<"Enter number of hours worked:";
    double h;
    cin>>h;
    cout<<"First format:\n";
    cout.setf(ios_base::right,ios_base::adjustfield);
    cout.width(15);
    cout<<st<<":$";
    cout.width(5);
    cout<<wa<<":";
    cout.width(5);
    cout<<h<<endl;;
    cout.setf(ios_base::left,ios_base::adjustfield);
    cout.width(15);
    cout<<st<<":$";
    cout.width(5);
    cout<<wa<<":";
    cout.width(5);
    cout<<h;
    cout<<endl;
    return 0;
}
