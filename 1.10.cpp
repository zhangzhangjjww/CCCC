#include<iostream>
int main()
{
    int sum1=0;int sum2=0;
    for(int i=50;i<=100;i++)
        sum1=sum1+i;
    int j=50;
    while(j<=100)
    {
        sum2=sum2+j;
        j++;
    }
    std::cout<<sum1<<" "<<sum2<<std::endl;
}
