#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        //�Ӻ���ǰά��һ��ջ
        stack<int> stack;
        vector<int> result;
        stack.push(-1);//���ұߵ�һ��û����һ���ϴ�Ԫ��
        //�����ǰջΪ����ֱ����ջ
        //��Ϊ���򵯳�top�����topԪ�ش��ڵ�ǰԪ����Ϊ�ϴ�Ԫ��
        //���topԪ��С�ڵ�ǰԪ�أ����������ֱ��-1���ߴ��ڵ�ǰԪ��
        for(int i=n-1;i>=0;--i)
        {
            int top = stack.top();
            while(top!=-1&&A[i]>=top)
            {
                stack.pop();
                top = stack.top();
            }
			
            result.insert(result.begin(),top);
            stack.push(A[i]);
        }
        return result;
    }
};