#include<iostream>

using namespace std;

const int N=16;
int Bit_Reverse(int v) ;
int bit_reversed_increment(int c);

int main()
{
    int a[N],b[N];
    for(int i=0;i!=N;++i)
        a[i]=i;
    int j=0;
    do
    {
        int k=bit_reversed_increment(j);
        b[Bit_Reverse(j)]=a[j];
        j=k;
    }
    while(j!=0);
    for(int i=0;i!=N;++i)
        cout<<a[i]<<" "<<Bit_Reverse(i)<<" "<<b[i]<<endl;
    return 0;
}

 int Bit_Reverse( int c)
{
    c = ( c & 0x5 ) << 1 | ( c & 0xA ) >> 1;
    c = ( c & 0x3 ) << 2 | ( c & 0xC ) >> 2;
    //c = ( c & 0x3 ) << 4 | ( c & 0xc ) >> 4;
    return c;
}

int bit_reversed_increment(int c)
{
    return Bit_Reverse(Bit_Reverse(c)+1);
}
