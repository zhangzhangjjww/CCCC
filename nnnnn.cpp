#include<iostream>
#include<vector>

using namespace std;


  bool search(int pos,vector<int>& vol) {
        if(vol.empty()) {
            return false;
        }
        for(int i=0;i!=vol.size();++i) {
            if(vol[i]==pos) {
                return true;
            }
        }
        int tmp=vol[vol.size()-1];
        if(pos==tmp+1||pos==tmp-1) {
            return true;
        }
        return false;
    }
    void solve(vector<vector<string>>& re,int pos,vector<string> val,vector<int> vol,int n) {
        if(pos==n) {
            re.push_back(val);
        }
        else {
            int i=0;
            for(;i<n;++i) {
                if(search(i,vol)) {
                    continue;
                }
                else {
                    string s;
                    for(int j=0;j<i;++j) {
                        s+='.';
                    }
                    s+='Q';
                    for(int j=i+1;j<n;++j) {
                        s+='.';
                    }
                    vector<int> vol1=vol;
                    vector<string> val1=val;
                    val1.push_back(s);
                    vol1.push_back(i);
                    cout<<"pos:"<<pos<<endl;
                    cout<<"i:"<<i<<endl;
                    cout<<"s:"<<s<<endl;
                    cout<<"vol:";
                    for(int i=0;i!=vol1.size();++i) {
                        cout<<vol1[i]<<" ";
                    }
                    cout<<endl;
                    solve(re,pos+1,val1,vol1,n);
                }
            }
        }
    }
  vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> re;
       if(n==0||n==2||n==3) {
           return re;
       }
       if(n==1) {
           vector<string> tmp;
           tmp.push_back("Q");
           re.push_back(tmp);
           return re;
       }
       vector<string> val;
       vector<int> vol;
       solve(re,0,val,vol,n);
       return re;
    }

int main()
{
    //vector<int> v;
   // int a[12]={5,9,3,2,1,0,2,3,3,1,0,0};
//[5,9,3,2,1,0,2,3,3,1,0,0]
    vector<vector<string>> re=solveNQueens(5);
    for(int i=0;i!=re.size();++i) {
        for(int j=0;j!=re[i].size();++j) {
            cout<<re[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
