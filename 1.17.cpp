#include<iostream>
int main()
{
    int n=10;int v;int c=0;
    std::cout<<"Please enter 10 numbers:";
    for(int i=0;i!=10;i++)
    {
        std::cin>>v;
        if(v<0)
            c=c+1;
    }
    std::cout<<"In 10 numbers have(has) "<<c<<" negative number(s)."<<std::endl;
    return 0;
}
