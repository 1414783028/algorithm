#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
��
ǰ��GDAFEMHZ
����: ADEFGHMZ
*/
/*
����ǰ�����򣬹�����������������������
*/
void inPre2Post(char* pInOrder, char* pPreOrder,int nLength,char *pPostOrder,int& nIndex)
{
    if(nLength <= 0)
		return;
	if(nLength == 1)
	{
	  pPostOrder[nIndex] = *pPreOrder;
	  nIndex++;
	  return;
	}
	char root = *pPreOrder;
	int nRoot = 0;
	for(;nRoot < nLength;nRoot++)
	{
	   if(pInOrder[nRoot] = root)
	   break;
	}
	inPre2Post(pInOrder,pPreOrder+1,nRoot,pPostOrder,nIndex);//�ݹ�������
	inPre2Post(pInOrder+nRoot+1,pPreOrder+nRoot+1,nLength-nRoot-1,pPostOrder,nIndex);//�ݹ�������
	pPostOrder[nIndex] = root;//����������һ����㼴Ϊ�����
	nIndex++;
}
