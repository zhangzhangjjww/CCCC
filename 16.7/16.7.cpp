#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> lotto(int n1,int n2);

int main()
{
    vector<int> winners;
    cout<<"Please enter the sum number:";
    int sum;cin>>sum;
    cout<<"Enter the number:";
    int nu;
    cin>>nu;
    winners=lotto(sum,nu);  cout<<"the winners is:";
    for(vector<int>::iterator p=winners.begin();p!=winners.end();p++)
    {
      cout<<*p<<"    ";

    }
    cout<<endl;
    return 0;
}

vector<int> lotto(int n1,int n2)
{
    vector<int> temp(n1);
    for(int i=0;i<n1;i++)
        temp[i]=i+1;
    vector<int>::iterator p1=temp.begin();
    vector<int>::iterator p2=temp.end();
    vector<int> tt(n2);
    for(int i=0;i<n2;i++)
    {
        random_shuffle(p1,p2);
        tt[i]=temp[0];
    }
    return tt;
}
