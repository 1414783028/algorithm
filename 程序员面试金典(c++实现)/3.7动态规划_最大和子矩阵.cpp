#include<iostream>
#include<vector>
using namespace std;
/*
���ӵ�i�е���j�е�ÿһ������ͬ�еļ����������Եõ�һ��һά�������£�
     (ai1+����+aj1, ai2+����+aj2, ����,ain+����+ajn)
     �ɴ����ǿ��Կ����������ľ��Ǵ�һά���������Ӷκ�����
*/
class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        int value[200]={0};
        int maxv=0;
        for(int i=0;i<n;i++)      //�����
        {
            for(int j=0;j<n;j++)  //��ռ�¼ֵ����
            {
                value[j]=0;
            }
            for(int j=i;j<n;j++)  //����ʼ������һ���ۼ�
            {
                int sum=0;
                for(int k=0;k<n;k++)  //����ÿ�У������ϲ��У���ÿһ��
                {
                    value[k]+=mat[j][k];
                }
                sum = MaxSum(value,n);
                if(sum>maxv)
                {
                    maxv=sum;
                }
            }
        }
        return maxv;
    }
     
	int MaxSum(int vec[], int n)
	{
		int maxv=0;
		int val=0;
		for(int i=0;i<n;i++)
		{
			if(val>0)
			{
				val+=vec[i];
			}
			else
			{
				val=vec[i];
			}
 
			if(val>maxv)
			{
				maxv=val;
			}
		}
		return maxv;
	}
};
