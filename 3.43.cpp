#include<iostream>
#include<cstddef>

int main()
{
    using namespace std;
    int a[3][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11}};
   // using re=int [4];
    //typedef int  ree[4];
    for(auto &p : a)
        for(auto & q : p)
        cout<<q<<endl;
    for(size_t i=0;i!=3;i++)
        for(size_t j=0;j!=4;j++)
        cout<<a[i][j]<<endl;


    for(auto i=begin(a);i!=end(a);i++)
        for(auto j=begin(*i);j!=end(*i);j++)
        cout<<*j<<endl;
    return 0;
}
