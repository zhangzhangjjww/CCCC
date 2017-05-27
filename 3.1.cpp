#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    cout<<"Please enter two number.\n";
    cout<<"Base:";
    int base,exponent;
    cin>>base;
    cout<<"Exponent:";
    cin>>exponent;
    int result=1;
    for(int i=0;i!=exponent;i++)
        result*=base;
    cout<<"The result is "<<result<<endl;
    return 0;
}
