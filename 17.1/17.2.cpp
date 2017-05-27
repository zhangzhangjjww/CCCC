#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string st;
    ofstream fout;int c=0;
    fout.open("zz.txt");
    if(fout.is_open())
    {
        cout<<"Enter a string:";
        while(cin>>st)
        {
            fout<<st<<" ";
            c++;
        }
        cout<<"total:"<<c<<endl;

    }
    return 0;
}
