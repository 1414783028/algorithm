#include<iostream>
#include<string>
using namespace std;
class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        // write code here
   /*
    1. a*b��������ת����|b|��a��ӣ�����|a|��b��ӣ�������a��b�ķ���ȷ������ֵ�ķ��š�
    2.  a-b��ת����a+[-b]������[b]����[-b]��֮���ת����ϵ����ͬ����λһ��λȡ�����ټ�1
   */ 
    switch (type) {
        case 1:
            return multiply(a, b);
        case 0:
            return divide(a, b);
        default:
            return minus(a, b);
     }
   }
public:
    int multiply(int a, int b) 
    {
        
        if(abs(a)<abs(b))
        {
            int temp = b;
            b = a;
            a = temp;
        }
        int sum = 0;
        for(int i=0;i<abs(b);i++)
        {
            sum+=a;
        }
        return b>0?sum:~sum+1;
    }
public:
     int minus(int a, int b)
     {
        int rb = ~b+1;
        return a+rb ;
     } 
public:
     int divide(int a, int b)
     {
        // b * x = a ��x
         int sum = 0;
         unsigned int count = 0;
         while(sum<abs(a)){
             sum+=abs(b);
             count++;
         }
        sum = sum>abs(a)?--count:count;
         //a bͬ�ŷ�������
        return  ((a>>31)^(b>>31))==0?count:~count+1;
     }
};