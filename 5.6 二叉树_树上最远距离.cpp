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

class LongestDistance {
public:
    int depth(TreeNode* root,int &dep)
    {
        if(root==NULL) return 0;
        int left = depth(root->left,dep);
        int right = depth(root->right,dep);
        dep = dep > (left+right+1)?dep:(left+right+1);
        return left>right?(left+1):(right+1);
        
    }
    int findLongest(TreeNode* root) {
        /*
        ���A: ·������������������ڵ㣬ͨ�����ڵ㣬�ٵ�������������ڵ㡣
        ���B: ·�����������ڵ㣬��������������������������·����ȡ����ߡ�
        */
        int dep = 0;
        depth(root,dep);
        return dep;
    }
};