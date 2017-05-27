#include<iostream>

using namespace std;
int main()
{
    char ch;
    cout<<"Enter the string unil $\n";
    int c=0;
    while(cin.get(ch)&&ch!='$')
    {
        c++;

    }
    cin.putback(ch);
    char ch1;
    ch1=cin.get();
    cout<<ch1<<endl;
    cout<<"total:"<<c<<endl;
    return 0;
}
