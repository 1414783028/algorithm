#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        /*
        1.��������������ķǵݹ��㷨��
        2.�޸ĵ�ǰ�����ڵ���ǰһ�����ڵ��ָ��ָ��
        */
        if(pRootOfTree == NULL) return NULL;
        stack<TreeNode* > stack;
        TreeNode* root =NULL;
        TreeNode* pre = NULL;
        while(pRootOfTree || !stack.empty())
        {
           while(pRootOfTree)
           {
               stack.push(pRootOfTree);
               pRootOfTree = pRootOfTree->left;
           }
           if(!stack.empty())
           {
                pRootOfTree = stack.top();
                stack.pop();
                if(root == NULL)
                {
                    root = pRootOfTree;
                    pre = root;
                 
                }
                else
                {
                    pre->right = pRootOfTree;
                    pRootOfTree->left = pre;
                    pre = pRootOfTree;
                }  
                pRootOfTree = pRootOfTree->right;  
           }
        }
       return root;
    }
};