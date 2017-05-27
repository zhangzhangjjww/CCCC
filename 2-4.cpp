#include<stdio.h>
#include<string.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start,int len)
{
    int i;
    for(i=0;i<len;++i)
        printf("%.2x",start[i]);
    printf("\n");
}

int main()
{
    int x1=5;float x2=12345.0;void* x3=0;
    printf("%d\n",sizeof(int));
    show_bytes((byte_pointer)&x1,sizeof(int));
    show_bytes((byte_pointer)&x2,sizeof(float));
    show_bytes((byte_pointer)&x3,sizeof(void*));
    const char* s="abcdef";
    show_bytes((byte_pointer)s,strlen(s));
    return 0;
}
