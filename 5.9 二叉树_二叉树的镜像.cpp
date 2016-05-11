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
    void Mirror(TreeNode *pRoot) {
       if(pRoot == NULL) return;
       stack<TreeNode* > tmp;
       while(pRoot || !tmp.empty())
       {
           while(pRoot)
           {
               tmp.push(pRoot);
               pRoot = pRoot->left;
           }
           pRoot = tmp.top();
           tmp.pop();
           
           TreeNode* temp = pRoot->left;
           pRoot->left = pRoot->right;
           pRoot->right = temp;
         //�����˴�Ӧ�÷�������������Ϊ������Ϊ����������
           pRoot = pRoot->left;  
       }
    }
};