#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
 
class FindErrorNode {
public:
    void mid(TreeNode* root,vector<int> &ret)
    {
        if(root==NULL) return;
        mid(root->left,ret);
        ret.push_back(root->val);
        mid(root->right,ret);
    }
    vector<int> findError(TreeNode* root) {
       
        //��һ�ν���Ľϴ�ֵ  �ڶ��ν���Ľ�Сֵ
        vector<int> ret;
        mid(root,ret);
        int a = -1,b = -1;
        for(int i=0;i<ret.size();i++)
        {
            if(ret[i]<ret[i-1])
            {
                a = a==-1?ret[i-1]:a;
                b = ret[i];
            }
        }
        vector<int> res;
        res.push_back(b);
        res.push_back(a);
        return res;
    }
};