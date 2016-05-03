#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
            ListNode* ret=new ListNode(val);
        if(A.size()==0){          
            //ret->next=ret;
            return ret;
        }
        ListNode* head=new ListNode(A[0]);
        ListNode* p=head;
        ListNode* tmp;
        for(int i=0;i<nxt.size()-1;i++){
            tmp=new ListNode(A[nxt[i]]);
            p->next=tmp;
            p=tmp;
        }
        //p->next=head;
         //���val����ͷ�ڵ��ֵ�����ͷ�ڵ�
        //�����β��
        //������м�λ�ã�����Ҫ��ֹ����
        if(val<=head->val){
            ret->next=head;
            head=ret;
            return head;
        }
        else if(val>=p->val){
            p->next=ret;
            //ret->next=head;
            return head;
        }
        else{
            ListNode* front=head;
            ListNode* pnext=head->next;
            while(pnext!=NULL){
                if(front->val<=val && val<=pnext->val){
                    front->next=ret;
                    ret->next=pnext;
                    break;
                }
                front=front->next;
                pnext=pnext->next;
            }
            return head;
        }
    }
};