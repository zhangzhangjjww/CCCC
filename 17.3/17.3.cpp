#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(int argc,char * argv[])
{
    if(argc==1)
    {
        cerr<<"Usage:"<<argv[0]<<
        " filesname[s]\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin;
    char ch;
    ofstream fout;
    fin.open(argv[1],ios::in);
    if(!fin.is_open())
    {
        cerr<<"Could not open "<<argv[1]<<endl;
        fin.clear();

    }

    fout.open(argv[2],ios::out|ios::trunc);
    if(!fout.is_open())
    {
        cerr<<"Could not opeen "<<argv[2]<<endl;
        fout.clear();

    }
    while(fin.get(ch))
        fout<<ch;
    cout<<"done.";
    system("pause");
    return 0;
}
