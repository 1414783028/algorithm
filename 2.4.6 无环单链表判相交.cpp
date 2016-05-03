#include<iostream>
using namespace std;
//������������õ����ȣ�Ȼ���������߲�ֵ��һ����ʱ����ͬ���ߣ���ͬʱ���������ڵ㡣
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class CheckIntersect {
public:
    bool chkIntersect(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        unsigned int length1 = 0;
        unsigned int length2 = 0;
        while(p1)
        {
            p1 = p1->next;
            length1++;
        }
         while(p2)
        {
            p2 = p2->next;
            length2++;
        }
        p1 = headA; 
		p2 = headB;
       if(length1>=length2)
       {
           unsigned int tmp = length1-length2;
		   while(tmp--)
		   {
			   p1 = p1->next;
		   }
       }
        else
        {
           unsigned int tmp = length2-length1;
		   while(tmp--)
		   {
			   p2 = p2->next;
		   }
        }
	   while(p1 && p2)
	   {
		   if(p1 == p2)
		   {
		      return true;
		   }
		  p1 = p1->next;
		  p2 = p2->next;
	   }
        return false;
    }
};