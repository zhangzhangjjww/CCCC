#include<iostream>
#include<bitset>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main()
{

    bitset<32> b;
    int i=1;int j=2;int c;
    b.set(i);b.set(j);
    for(int k=0;k!=5;k++)
    {
        b.set(i+j);
        c=i;
        i=j;
        j=c+i;
    }
    cout<<b<<endl;
    return 0;
}
