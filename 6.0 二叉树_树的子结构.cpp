#include <iostream>
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
    bool DoesTree1hasTree2(TreeNode *tree1, TreeNode *tree2)
    {
        if(tree2==NULL)
        {
            return true;
        }
         
        if(tree1==NULL)
        {
            return false;
        }
         
        if(tree1->val !=tree2->val)
        {
           return false; 
        }
        
        return DoesTree1hasTree2(tree1->left,tree2->left)&&DoesTree1hasTree2(tree1->right,tree2->right);   
    }
     /*
	 ��һ�� ����A���ҵ���B�ĸ�����ֵһ���Ľ��R
	 �ڶ������ж���A����RΪ�����������ǲ��ǰ�����Bһ���Ľṹ
	 */
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result=false;
        if(pRoot1!=NULL && pRoot2!=NULL)
        {
            if(pRoot1->val==pRoot2->val)
            {
                result=DoesTree1hasTree2(pRoot1,pRoot2);
            }
            if(!result)
            {
                result = HasSubtree(pRoot1->left,pRoot2)|| HasSubtree(pRoot1->right,pRoot2);
            }
        }
        return result;
    }
};