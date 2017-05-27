
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void main( void )
{
    double n=0;int i=0;int b=0;
      srand(time( NULL ) );

    for(i=1;i!=100;i++)



    {n=rand()%1000;
    n=n/1000;
    b=n*10;
    printf("%f\n",n);
    printf("%d\n",b);
   }

}
