#include<iostream>
#include"port.h"
int main()
{
    using namespace std;
    Port p1;
    Port p2("Gallo","twany",20);
    Port p3(p2);
    Port p4=p1;
    p3-=8;
    p4+=10;
    p1.show();p2.show();p3.show();p4.show();
    cout<<p1<<p2<<p3<<p4<<endl;
    VintagePort v1;
    VintagePort v2("debug",55,"bug",1899);
    VintagePort v3(v2);
    VintagePort v4=v1;
    v3-=10;
    v4+=98;
    v1.show();v2.show();v3.show();v4.show();
    cout<<v1<<v2<<v3<<v4<<endl;
    return 0;
}
