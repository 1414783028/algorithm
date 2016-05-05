#include <iostream>
using namespace std;
//���ں�����������һ��Ԫ��Ϊ����㣬
//���ݸý�㽫����ֳ�ǰ������,ʹ��ǰ��ζ�С�ڸ���㣬���η�֮
bool canPostOrder(const int *a,int size)
{
  int left = 0;
  int root = a[size-1];
  for(int i=0;i<size;i++)
  {
	if(a[i] > root) break;
     left++;
  }
  int right =size-2;
  while(right>=0)
  {
	if(a[right] < root) break;
     right--;
  }
  if(left != right+1)
  {
     return false;
  }
  return canPostOrder(a,left) 
	  && canPostOrder(a+left,size-left-1);
}
int main(int argc,char* argv[])
{
	int a[] ={1,2,5,4,3};
	bool b = canPostOrder(a,sizeof(a)/sizeof(int));
	cout<<b<<endl;
	return 0;
}