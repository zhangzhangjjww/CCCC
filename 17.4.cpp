#include<iostream>
#include<fstream>
#include<string>

int main()
{
    using namespace std;
    fstream fout1,fout2,fout3;int n1=0;int n2=0;
    fout1.open("a.txt",ios_base::out|ios_base::in);
    string str;
    cout<<"Enter string:";
    getline(cin,str);
    while(cin&&str!="quit")
    {
        fout1<<str<<endl;n1++;
        getline(cin,str);

    }
    fout2.open("b.txt",ios_base::out|ios_base::in);

    if(fout2.is_open())
    {
        cout<<"Enter a string:";
        getline(cin,str);
    while(cin&&str!="quit")
    {
        fout2<<str<<endl;n2++;
        getline(cin,str);
    }
    }
    cout<<n1<<" "<<n2<<endl;
    fout1.close();fout2.close();
    fout3.open("c.txt",ios_base::in|ios_base::out);
    ifstream fin1,fin2;
    fin1.open("a.txt");fin2.open("b.txt");
    int m1=(n1>n2?n1:n2);
    int m2=(n1<n2?n1:n2);
    if(fout3.is_open())
    {
        int j;
        for(j=0;j<m2;j++)
        {
            getline(fin1,str);
            cout<<str;
            fout3<<str<<" ";
            getline(fin2,str);
            fout3<<str<<endl;
        }
        for(j=m2;j<m1;j++)
        {
            if(n1>n2)
            {
              getline(fin1,str);
            fout3<<str<<endl;
            }
            else
            {
                getline(fin2,str);
            fout3<<str<<endl;
            }
        }
    }
    return 0;
}
