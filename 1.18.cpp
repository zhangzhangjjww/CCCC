#include<iostream>
int main()
{
    int v1,v2;int v;int cou=0;
    std::cout<<"Please enter two number:";
    std::cin>>v1>>v2;
    if(v1>v2)
    {
        v=v1;v1=v2;v2=v;
    }
    for(int i=v1;i<=v2;i++)
    {
        cou++;
        std::cout<<i<<" ";
        if(cou%10==0)
            std::cout<<std::endl;
    }
    return 0;
}
