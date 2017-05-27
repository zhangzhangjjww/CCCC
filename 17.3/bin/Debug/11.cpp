#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{

    ifstream fin;
    char ch;
    ofstream fout;
    fin.open("zs.txt.");
    if(!fin.is_open())
    {
        cerr<<"Could not open "<<endl;
        fin.clear();

    }

    fout.open("zz.txt");
    if(!fout.is_open())
    {
        cerr<<"Could not opeen "<<endl;
        fout.clear();

    }
    while(fin.get(ch))
        fout<<ch;
    cout<<"done.";
    system("pause");
    return 0;
}
