#include<iostream>
#include<list>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> vi0(100000);
    for(int i=0;i<100000;i++)
    {
        srand(time(0));
        vi0[i]=rand();
    }
    vector<int> vi=vi0;
    list<int> li(100000);
    for(int i=0;i<100000;i++)
        li.insert(li.end(),vi0[i]);
    clock_t start=clock();
    sort(vi.begin(),vi.end());
    clock_t en=clock();
    cout<<(double)(en-start)/CLOCKS_PER_SEC<<endl;
    start=clock();
    li.sort();
     en=clock();
    cout<<(double)(en-start)/CLOCKS_PER_SEC<<endl;
      for(int i=0;i<100000;i++)
        li.push_back(vi0[i]);


    copy(li.begin(),li.end(),back_inserter(vi));
    start=clock();
     sort(vi.begin(),vi.end());
     copy(vi.begin(),vi.end(),back_inserter(li));

     en=clock();
    cout<<(double)(en-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
