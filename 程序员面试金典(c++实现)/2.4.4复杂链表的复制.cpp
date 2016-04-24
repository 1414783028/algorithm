#include<iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)return pHead;
        //ÿ���ڵ�ֱ𿽱�һ��������棬Ȼ����ԭ���ĺͿ���randomָ�����Ӧ�Ľڵ�,������
        RandomListNode *p = pHead;
        RandomListNode *pnext = NULL;
        //����
        while(p != NULL)
        {
            pnext = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = pnext;
            p = pnext;
        }
        //ÿ�θ���ԭʼ�ĺͿ����Ľڵ�һ��������randomָ��ָ�����
        RandomListNode *cp = NULL ;
        p = pHead;
        while(p != NULL)
        {
            cp =  p->next;
            pnext =  p->next->next;
            cp->random = p->random != NULL ? p->random->next : NULL;
            p = pnext;
        }
        //����
        RandomListNode *res = pHead->next;
        p = pHead;
        while (p != NULL)
        {
            cp = p->next;
            pnext =  p->next->next;
            p->next =pnext;
            cp->next = pnext != NULL ? pnext->next: NULL;
            p = pnext;
        }
        return res;
    }
};