#include <iostream>
using namespace std;
int MaxSubArray(const int* a,int size)
{
	if(!a || size <=0)
	{
	  return 0;
	}
	int sum = a[0];//��ǰ�Ӵ��ĺ�
	int result = sum;//��ǰ�ҵ������Ž�
	for(int i=1;i<size;i++)
	{
		if(sum > 0)
		{
		  sum += a[i];
		}
		else
		{
		  sum = a[i];
		}
		result = max(sum,result);
	}
	return result;
}