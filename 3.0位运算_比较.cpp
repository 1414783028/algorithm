#include<iostream>
using namespace std;
class Compare {
public:
    int getMax(int a, int b) {
        // write code here
       // ���ǿ��Եõ�a-b�ķ��ţ����ݸ÷��ž�������a��b
           int c=a-b;
           int flag=((c>>31)&1^1);
           int flag_inv=1-flag;
           return flag*a+flag_inv*b;
    }
};