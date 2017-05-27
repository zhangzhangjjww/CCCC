#include"Item_base.h"

using namespace std;

int main()
{
    vector<Item_base*> v;
    double sum=0;
    Item_base *p1=new Item_base("zz",10);
    Item_base *p2=new Bulk_item("zz",20,"on",0.5,3);
    Item_base *p3=new Item_base("zz",30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for(vector<Item_base*>::iterator i=v.begin();i!=v.end();++i)
        sum+=(*i)->net_price(5);
    cout<<sum<<endl;
    delete p1;delete p2;delete p3;
    return 0;
}
