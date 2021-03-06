#include<iostream>
#include<string>
using namespace std;
class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        // write code here
   /*
    1. a*b：将问题转换成|b|个a相加，或者|a|个b相加，最后根据a、b的符号确定返回值的符号。
    2.  a-b：转化成a+[-b]补，而[b]补与[-b]补之间的转换关系：连同符号位一起按位取反，再加1
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
        // b * x = a 求x
         int sum = 0;
         unsigned int count = 0;
         while(sum<abs(a)){
             sum+=abs(b);
             count++;
         }
        sum = sum>abs(a)?--count:count;
         //a b同号返回正数
        return  ((a>>31)^(b>>31))==0?count:~count+1;
     }
};