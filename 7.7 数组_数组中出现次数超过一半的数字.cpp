#include<iostream>
using namespace std;
int main()
{
     /*
    ͬʱɾ��������ͬ�������������䡣 ������������¼һ����x��
    ��һ���� y�� ��x��ͬ�Ļ��Ͱ�x ,y�����ˣ�
    �൱���ӵ�������ͬ��������x��ͬ�Ļ����ͰѼ�������1��
    */  
    int m,n;
    cin>>m>>n;
    int time,res;
    for(int i=m*n,time=0;i;--i)
    {
        int a;
        cin>>a;
        if(time==0)
        {
            res = a;
        }
        if(a==res)
        {
            time++;
        }
        else
        {
            time--;
        }
    }
    cout<<res<<endl;
    return 0;
}