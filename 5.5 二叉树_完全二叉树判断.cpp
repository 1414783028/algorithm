#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        /*
        �����ǰ�ڵ�û�����ӵ������Һ��ӣ���return false
        �����ǰ�ڵ㲢�������Һ��Ӷ��У����ӱ���Ϊ��Ҷ�ڵ㣬����return false
        */
        queue<TreeNode*> qe;
        int isEnd = 0;
        if(root==NULL) return true;
        qe.push(root);
        while(!qe.empty())
        {
            TreeNode* cur = qe.front();
            qe.pop();
            if(isEnd&(cur->left!=NULL || cur->right!=NULL))
            {
                return false;  
            }
            else if(cur->left==NULL && cur->right!=NULL)
            {
                return false;
            }
            else if(cur->left==NULL && cur->right==NULL)
            {
                isEnd = 1;
            }
            else if(cur->left!=NULL && cur->right==NULL)
            {
                 isEnd = 1;
                qe.push(cur->left);   
            }
            else
            {
                qe.push(cur->left);
                qe.push(cur->right);
            }   
        }
        return true;
    }
};