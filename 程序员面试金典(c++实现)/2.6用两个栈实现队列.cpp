#include<iostream>
#include<stack>
using namespace std;
class Solution
{
    //�����ȳ�
    //��ʱ��ջ2�Ƿ�Ϊ�գ���Ϊ�գ���ջ2Ԫ�ص��ص�ջ1����ʱ����ջ1Ԫ��ȫ������ջ2�У�ֱ��ջ1Ϊ�ա�
public:
    void push(int node) {
        while(!stack2.empty()){
           stack1.push(stack2.top()); 
           stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {  
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }  
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};