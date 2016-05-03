#include<iostream>
using namespace std;
struct ListNode
{
  int val;
  struct ListNode *next;
  ListNode(int x):val(x),next(NULL){}
};
/*
С������ʹ������������ɺ����������ӣ�ע��ͷ���Ҳ��ֵ
*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        ListNode *p = pHead;
        ListNode *smallList = new ListNode(-1);
        ListNode *bigList = new ListNode(-1);
        ListNode *small = smallList;
        ListNode *big = bigList;
        while(p)
        {
            if(p->val < x)
            {
              small->next = p;
              small = p;
            }else{
              big->next = p;
              big = p; 
            }
            p = p->next;
        }
        big->next = NULL;
        small->next = bigList->next;
        return smallList->next;
    }
};

void main()
{
  system("pause");
}