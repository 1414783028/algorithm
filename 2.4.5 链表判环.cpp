#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
�л�ʱ������ָ�����ָ������ʱ���ÿ�ָ�����ͷ�ڵ㣬
һ�α���һ��,��ָ��һ�α���һ�����ڽ��뻷�ĵ�һ���ڵ��ٴ�����
*/
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        // write code here
        if(head==NULL || head->next==NULL)return -1;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!= NULL && fast != NULL && fast->next != NULL)
        {
          
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                fast = head;
                break;
            }
        }
        if(fast == head)
        {
            while(fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast->val;
            
        }
        return -1;
    }
};