#include<iostream>
int main()
{
    int base,exponent;char _;float Float=3.14f;
    int month=011,day=07;
    int car=1024,carr=2048;std::cout<<carr<<std::endl;
    std::cout<<"Please enter the base and the exponent\n";
    std::cout<<"Base:";
    std::cin>>base;
    std::cout<<"Exponent:";
    std::cin>>exponent;
    double result=1;
    for(int i=0;i!=exponent;i++)
    {
        result*=base;

    }
    std::cout<<"The base of "<<base<<"'s "<<exponent<<" exponent result is "<<result<<std::endl;
    return 0;
}
