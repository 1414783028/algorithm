#include <iostream>
using namespace std;
typedef struct tagSBucket
{
  bool bValid;
  int nMin;
  int nMax;
  tagSBucket():bValid(false){}
  void Add(int n)//����n���뵽Ͱ��
  {
	  if(!bValid)
	  {
	    nMin = nMax = n;
		bValid = true;
	  }
	  else
	  {
		  if(nMax<n)
               nMax = n;
		  else if(nMin > n)
			  nMin = n;
	  }
  }
}SBucket;

int CalcMaxGap(const int* A,int size)
{
	SBucket* pBucket = new SBucket[size];
	int nMax = A[0];
	int nMin = A[0];
	int i;
	for(int i=1;i<size;i++)
	{
	   if(nMax<A[i])
               nMax = A[i];
		  else if(nMin > A[i])
			  nMin = A[i];
	}
	//���ν����ݷ���
	int delta = nMax-nMin;
	int nBucket;//ĳ��Ӧ�����ĸ�Ͱ��
	for(i=0;i<size;i++)
	{
	   nBucket = (A[i]-nMin)*size/delta;
	   if(nBucket>=size){
	     nBucket = size-1;
	   }
	   pBucket[nBucket].Add(A[i]);
	}
	//������ЧͰ�ļ��
	i = 0;//��һ���϶�����Ч��
	int nGap = 0;//��С���
	int gap;
	//i��ǰһ��Ͱ��j�Ǻ�һ��Ͱ
	for(int j=1;j<size;j++)
	{
		if(pBucket[j].bValid)
		{
			gap = pBucket[j].nMin-pBucket[i].nMax;
			if(nGap < gap)
			{
			  nGap = gap;
			}
			i = j;
		}
	}
	return nGap;
}