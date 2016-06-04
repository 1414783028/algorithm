#include<iostream>
using namespace std;
int query(string s,string t)
{
    //�û�Ǯ������ remain��ʾ��Ƿ���٣���Ч�黹���Լ�
    //right��ʾ��������
    //left��ʾ�໹�����ջض���
    /*
    ����s=aabbcdcba t=abc
    */
    int remain = t.size();
    int map[256]={0};
    int left = 0,right = 0,len=0x7ffffff;
    for(int i=0;i!=t.size();i++)
    {
       map[t[i]]++;
    }
    while(right!=s.size())
    {
        map[s[right]]--;
        if(map[s[right]]>=0)//��Ч����
        {
            remain--;
        }
        if(remain==0)
        {
            while(map[s[left]]<0)
            {
              map[s[left++]]++;
            }
            len = min(len,right-left+1);
            remain++;
            map[s[left++]]++;//��left����һ��λ�ü�����
        }
        right++;
    }
    return len;
}
int main()
{
    string s="aabbcdcba";
    string t="abc";
    int len = query(s,t);
    printf("%d\n",len);
    system("pause");
    return 0;
}