/************************************************************************/
/* �㷨����15.4-6
 * �ҳ�n��������������ĵ�������������
 * ʱ�临�Ӷ�ΪO(nlgn)*/
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
    cout<<"ԭ���г���Ϊ"<<N+1<<"�����£�"<<endl;
    for (int i=0;i<=N;i++)
    {
        nums[i]=i;//rand()%1000+1;
        cout<<nums[i]<<" ";
    }
    //����b�洢�ڵ����������е�ǰԪ�ص�ǰһ��Ԫ�����
    int b[N+1]={0}; //����b�洢�ڵ����������е�ǰԪ�ص�ǰһ��Ԫ�����,��������b�����ܻ�������������
    int last[N+1]={0},L=0;  //last�д洢����ͬ���ȵĵ���������(ͬһ���ȵ������У�ֻ����βԪ����С������)�����һ��Ԫ�ص����,����last�����������ҵ�������е����һ��Ԫ����š�
    for (int i=1;i<N+1;i++)//����������last�����ҵ�MAX���������һ��Ԫ���±����������b��������MAX�����С�
    {
        int low=0,high=L-1;

        if(nums[i]>nums[last[L==0?0:high]])
        {//�����ǰԪ�ر�last������Ԫ�ض���������������еĳ��ȼ�һ����βԪ��Ϊ��ǰԪ��nums[i]
            last[L++]=i;
            b[i]=last[high];cout<<last[high]<<high<<endl;
        }
        else
        {//����ʹ�ö��ַ���last�в��ҵ����ڵ��ڵ�ǰԪ��nums[i]����СԪ��
            while(low<=high)
            {
                int middle=(high+low)/2;
                if(nums[i]>nums[last[middle]])
                    low=middle+1;
                else
                    high=middle-1;
            }
            //����last�е�Ԫ��ֵ��b�е��±�ֵ��
            last[low]=i;
            b[i]=last[low==0 ? 0 : low-1];
        }
    }
    int len=L;
    cout<<endl;
    for(int i=0;i!=N+1;++i)
        cout<<last[i]<<" "<<b[i]<<endl;
    cout<<"��������������:"<<endl;
    printSequence(b,nums,last[len-1]);
    cout<<endl;
}
void printSequence(int *b,int* nums,int last)
{ //���ݷ�
    if(b[last]!=last)
        printSequence(b,nums,b[last]);
    cout<<nums[last]<<" ";
}
