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
/*
class CheckBalance {
public:
    int getTreeHight(TreeNode* p)
    {
        if(p==NULL) return 0;
        int l = getTreeHight(p->left), r = getTreeHight(p->right);
        return (l>r?l:r)+1;
    }
    bool check(TreeNode* root) {
        if(root==NULL)return true;
        if(abs(getTreeHight(root->left)-getTreeHight(root->right))>1)return false;
        if(!check(root->left)||!check(root->right)) return false;
        return true;
    }
};*/
/*
 * �ж����Ƿ���ƽ���������������
 * 1. ���������������Ȳ�ֵ<=1
 * 2. ���������������Ϊƽ����
 * ����˼������ʱÿ�ζ����ظ����㣬���Ӷ�̫��
 * ����Ľ�����ÿһ�������ʱ������������ò�߶ȣ�����������µݹ飬�������ֵ��������ϵģ�
 * �������в�ƽ���ֱ�����������Ż��ֵ����ڵ���Ͽ��Ƿ�Ϊƽ��
*/
class Balance {
public:
    bool checkTree(TreeNode* root ,int &high)
    {
        if(root == NULL)
        {
            high = 0;
            return true;
        }
        int leftHigh,rightHigh;
        if(!checkTree(root->left,leftHigh) || !checkTree(root->right,rightHigh))
        {
            return false;
        }
        if(abs(leftHigh-rightHigh)>1)return false;
        high = (leftHigh>rightHigh?leftHigh:rightHigh)+1;
        return true;
    }
    bool isBalance(TreeNode* root) {
       int high = 0;
       return checkTree(root, high);
    }
};