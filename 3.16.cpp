#include<iostream>
#include<vector>
#include<string>
int main()
{
    using namespace std;
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10,"hi"};
    cout<<v1.size()<<endl;cout<<endl;
    for(decltype(v2.size()) i=0;i!=10;i++)
        cout<<v2[i]<<endl;
        cout<<v2.size()<<endl;cout<<endl;
    for(decltype(v3.size())i=0;i!=10;i++)
        cout<<v3[i]<<endl;
    cout<<v3.size()<<endl;cout<<endl;
    cout<<v4[0]<<" "<<v4.size()<<endl;cout<<endl;
    cout<<v5[0]<<" "<<v5[1]<<" "<<v5.size()<<endl;cout<<endl;
    for(vector<string>::size_type i=0;i!=v6.size();i++)
    {
        cout<<v6[i]<<endl;
        cout<<v7[i]<<endl;

    }
    cout<<v6.size()<<" "<<v7.size()<<endl;
    return 0;

}
