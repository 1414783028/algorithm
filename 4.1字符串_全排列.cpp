#include <iostream>
using namespace std;
/*
�����ַ����и������ַ������ڵ�һλ��
�ú����һλ֮����ַ��ֱ�����ڵڶ�λ��
���ú����һ�ڶ�λ���ַ��ֱ�����ڵ���λ���������ơ�
ÿ�β�����ɺ���Ҫ���ַ����ָ�����ʼ״̬���������Ľ��������
*/
void print(const int* a,int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<' ';
	cout<< endl;
}
void permutation(int* a,int size,int n)
{
	if(n==size-1)
	{
	  print(a,size);
	  return;
	}
	//�ظ��ַ�
	int dup[256] = {0};
	for(int i=n;i<size;i++)
	{
	  if(dup[a[i]]==1)continue;
	  dup[a[i]] = 1;
	  swap(a[i],a[n]);
	  permutation(a,size,n+1);
	  swap(a[i],a[n]);
	}
}

int main()
{
	int a[] ={1,2,3,4};
	permutation(a,sizeof(a)/sizeof(int),0);
	system("pause");
	return 0;
}