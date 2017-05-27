#include<iostream>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
list<string> input();
void show( list<string>);
int main()
{
    list<string> l1;
    list<string> l2;
    cout<<"Please input Mat's friends'name(quit to quit):\n";
    l1=input();
    cout<<"After sort.Mat's friends' name:";
    show(l1);
    cout<<endl;
    cout<<"Please input Pat's friends'name(quit to quit):\n";
    l2=input();
    cout<<"After sort.Pat's friends' name:\n";
    show(l2);
    cout<<endl;
    l2.merge(l1);
    l2.sort();
    l2.unique();
    cout<<"After merger:";
    show(l2);
    return 0;

}
list<string> input()
{
    string name;list<string> temp;
    getline(cin,name);
    while(cin&&name!="quit")
    {
       temp.insert(temp.begin(),name);
       cout<<"Enter another string(quit to quit):\n";
       getline(cin,name);
    }
    temp.sort();
    return temp;
}
void show( list<string> l)
{
    list<string>::iterator p=l.begin();
    int i=0;
    for(;p!=l.end();p++)
    {
        cout<<*p<<'\t';;
        i++;
        if(i%4==0)
            cout<<endl;
    }
    cout<<endl;
}
