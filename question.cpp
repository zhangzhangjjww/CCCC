/************************************************************************/
/* 算法导论15.4-6
 * 找出n个数的序列中最长的单调递增子序列
 * 时间复杂度为O(nlgn)*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <ctime>
#include<cstdlib>
using namespace std;
#define N 9
void printSequence(int *b,int* nums,int last);
int main()
{
    srand( (unsigned)time( NULL ) );
    int nums[N+1]={0};
    cout<<"原序列长度为"<<N+1<<"，如下："<<endl;
    for (int i=0;i<=N;i++)
    {
        nums[i]=i;//rand()%1000+1;
        cout<<nums[i]<<" ";
    }
    //数组b存储在递增子序列中当前元素的前一个元素序号
    int b[N+1]={0}; //数组b存储在递增子序列中当前元素的前一个元素序号,根据数组b我们能回溯整个子序列
    int last[N+1]={0},L=0;  //last中存储各不同长度的递增子序列(同一长度的子序列，只考虑尾元素最小的序列)中最后一个元素的序号,根据last数组我们能找到最长子序列的最后一个元素序号。
    for (int i=1;i<N+1;i++)//所以我们用last数组找到MAX子序列最后一个元素下标后，利用数组b回溯整个MAX子序列。
    {
        int low=0,high=L-1;

        if(nums[i]>nums[last[L==0?0:high]])
        {//如果当前元素比last中所有元素都大则最长递增子序列的长度加一，其尾元素为当前元素nums[i]
            last[L++]=i;
            b[i]=last[high];cout<<last[high]<<high<<endl;
        }
        else
        {//否则使用二分法在last中查找到大于等于当前元素nums[i]的最小元素
            while(low<=high)
            {
                int middle=(high+low)/2;
                if(nums[i]>nums[last[middle]])
                    low=middle+1;
                else
                    high=middle-1;
            }
            //更新last中的元素值和b中的下标值。
            last[low]=i;
            b[i]=last[low==0 ? 0 : low-1];
        }
    }
    int len=L;
    cout<<endl;
    for(int i=0;i!=N+1;++i)
        cout<<last[i]<<" "<<b[i]<<endl;
    cout<<"公共子序列如下:"<<endl;
    printSequence(b,nums,last[len-1]);
    cout<<endl;
}
void printSequence(int *b,int* nums,int last)
{ //回溯法
    if(b[last]!=last)
        printSequence(b,nums,b[last]);
    cout<<nums[last]<<" ";
}
