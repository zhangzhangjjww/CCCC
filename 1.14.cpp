#include<iostream>
int main()
{
    std::cout<<"enter two number:"<<std::endl;
    int v1,v2;
    std::cin>>v1>>v2; // read input;
    //use smaller numbers as lower bound for summation
    // and large number as upper bound
    int lower,upper;
   if(v1<v2)
    {
        lower=v1;
        upper=v2;
    }
    else
    {
        lower=v2;
        upper=v1;
    }
    int sum=0;
    for(int val=lower;val<=upper;++val)
        sum+=val; //sum=sum+val;
    std::cout<<"sum of "<<lower<<" to "<<upper<<" inclusive is "<<sum<<std::endl;
    return 0;
}
