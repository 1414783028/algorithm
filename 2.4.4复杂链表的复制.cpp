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
        //每个节点分别拷贝一个在其后面，然后让原来的和拷贝random指向相对应的节点,最后分离
        RandomListNode *p = pHead;
        RandomListNode *pnext = NULL;
        //拷贝
        while(p != NULL)
        {
            pnext = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = pnext;
            p = pnext;
        }
        //每次各拿原始的和拷贝的节点一个，进行random指针指向操作
        RandomListNode *cp = NULL ;
        p = pHead;
        while(p != NULL)
        {
            cp =  p->next;
            pnext =  p->next->next;
            cp->random = p->random != NULL ? p->random->next : NULL;
            p = pnext;
        }
        //分离
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