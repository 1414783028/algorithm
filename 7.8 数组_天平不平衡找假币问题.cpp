#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int letter[12] = { 0 };
		int bad = 0;//��¼�м�����ƽ��ƽ��
		for (int i = 0; i < 3; i++)
		{
			string a, b, c;
			cin >> a >> b >> c;
			if (c == "up")
			{
				for (int j = 0; j < a.size(); j++)
					letter[a[j] - 65] ++;//����صĶ�+1
				for (int j = 0; j < b.size(); j++)
					letter[b[j] - 65] --;//�ұ���Ķ�-1
				bad++;//��ƽ�����+1
			}
			if (c == "down")
			{
				for (int j = 0; j < a.size(); j++)
					letter[a[j] - 65] --;
				for (int j = 0; j < b.size(); j++)
					letter[b[j] - 65] ++;
				bad++;
			}
			if (c == "even")
				for (int j = 0; j < a.size(); j++)
					letter[a[j] - 65] = letter[b[j] - 65] = 9; 
			//��һ����Ҫ��9  ��ʵֻҪ��һ����3��������� ��Ϊ�����3�β�ƽ��
		}
		for (int i = 0; i < 12; i++)
		{
			if (letter[i] == bad) //�����һ����bad��++
				cout << char(i + 65) << " is the counterfeit coin and it is heavy." << endl;
			if (letter[i] == -bad)//�����һ����bad��--
				cout << char(i + 65) << " is the counterfeit coin and it is light." << endl;
		}
	}	
	return 0;
}
