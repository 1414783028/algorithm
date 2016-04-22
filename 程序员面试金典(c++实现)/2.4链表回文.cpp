#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
       ListNode *slow = pHead;
       ListNode *fast = pHead;
      while(fast->next != NULL&&fast->next->next != NULL){
          slow = slow->next;//���slowָ���м�ڵ�
          fast = fast->next->next;//���fastָ�����һ���ڵ�
      }
      fast = slow->next;
      slow->next = NULL;
       //���ұ߽ڵ���ת
       ListNode *tmp = NULL;
       while(fast!=NULL)
        {
            tmp = fast->next;
            fast->next = slow;
           //��ֹ����
            slow = fast;
           //fast = fast->next;
            fast = tmp;
       }
        tmp = slow;//�������һ���ڵ�
        //��ʱslowָ�����һ���ڵ�
       fast = pHead;
       while(tmp != NULL && fast != NULL){
           if(tmp->val != fast->val){
               return false;
           }
           tmp = tmp->next;
           fast = fast->next;
       }
       return true;
	}
};