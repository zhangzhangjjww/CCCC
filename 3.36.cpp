#include<iostream>
#include<vector>

int main()
{
    using namespace std;
    int a1[10],a2[10];
    vector<int> v1,v2;
    for(int i=0;i!=10;i++)
    {
        a1[i]=i;a2[i]=i;
        v1.push_back(i);
        v2.push_back(i+1);
    }
    if(v1>v2)
        cout<<"v1"<<endl;
    else
        cout<<"v2"<<endl;int i;
    for(i=0;i!=10;i++)
    {
        if(a1[i]>a2[i])
          {

          cout<<"a1"<<endl;
            break;}
        if(a1[i]<a2[i])
          {
              cout<<"a2"<<endl;
            break;}
    }
           if(i==10)
            cout<<"a1 a2"<<endl;

    return 0;

}
