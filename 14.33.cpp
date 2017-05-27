#include<string>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

bool isShorter(const string& s1,const string & s2)
{
    return s1.size()<s2.size();
}

class GT_cls
{
public:
    GT_cls(size_t val=0,size_t val2=0):low(val),up(val2) {}
    bool operator()(const string& s)
    {
        return s.size()>=low&&s.size()<=up;
    }
private:
    string::size_type low;
    string::size_type up;
};
int main()
{
    vector<string> words;
    string next_word;
    while(cin>>next_word&&next_word!="q")
    {
        words.push_back(next_word);
    }
    sort(words.begin(),words.end());
    vector<string>::iterator end_unique=unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
    stable_sort(words.begin(),words.end(),isShorter);
    //cout<<"Enter a number:";
    cout<<count_if(words.begin(),words.end(),GT_cls(1,10));

    return 0;
}
