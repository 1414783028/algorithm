#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//Ҫ��ʱ�临�Ӷ�O(N)�ռ临�Ӷ�O(1)
int removeBlank(char *pString){
  //�����α�
	int j = 0;
	for(int i=0;pString[i]!='\0';i++)
	{
		if(pString[i]!=' ')
		{
			if(i!=j)
			{
			  pString[j] = pString[i];
			}
		   j++;
		}
	}
	pString[j] = 0;
	return 0;
}

int main()
{
  char str[] = "i have a dream";
  removeBlank(str);
  cout<<str<<endl;
  system("pause");
  return 0;
}