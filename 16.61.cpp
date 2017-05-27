#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

template <typename T> int compare(const T&,const T&);
template <class U,class V> int compare(U,U,V);
int compare(const char*,const char*);

int main()
{
   vector<int> ivec1(10),ivec2(20);
   int ia1[]={0,1,2,3,4,5,6,7,8,9};
   const char const_arr1[]="world",const_arr2[]="hi";
   char ch_arr1[]="world",ch_arr2[]="hi";
   cout<<compare(ch_arr1,const_arr2)<<endl;
   cout<<compare(0,0)<<endl;
   return 0;
}

template <typename T> int compare(const T& t1,const T& t2)
{
    cout<<"first one."<<endl;
    if(t1>t2)
        return 1;
    else
        if(t1<t2)
        return -1;
    else
        return 0;
}

template <class U,class V> int compare(U u1,U u2,V v)
{
    cout<<"second one"<<endl;
    U i;
    for(i=u1;i!=u2;++i)
    {
        if(*i>*v)
            return 1;
        else
            if(*i<*v)
            return -1;
        ++v;
    }
    if(i==u2)
        return 0;
}


int compare(const char* c1,const char *c2)
{
    cout<<"third one"<<endl;
    return strcmp(c1,c2);
}
