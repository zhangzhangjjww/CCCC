#include<iostream>
int main()
{
    std::cout<<"Please enter two number:";
    int v1,v2;
    std::cin>>v1>>v2;
    int v;
    if(v1>v2)
        v=v1;
    else
        v=v2;
    std::cout<<"The large number of "<<v1<<" and "<<v2<<" is "<<v<<std::endl;
    return 0;
}
