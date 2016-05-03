#include <iostream>
#include <vector>
using namespace std;
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n,int start=0,int end =0) {
        // write code here
        /*
        ��ʵ�ϣ�����A[5]=3ʱ����ǰ���������������Ҫ�ݹ������Ұ벿�֡���������������벿�֣�
        ���ǿ�������һЩԪ�أ�ֵ�ݹ�����A[0]��A[3]��Ԫ�ء�A[3]�ǵ�һ�����ܳ�Ϊħ��������Ԫ�ء�
        ���ϣ����ǵõ�һ������ģʽ���ȱȽ�midIndex��midValue�Ƿ���ͬ��
        Ȼ�������߲�ͬ�������·�ʽ�ݹ�������벿�ֺ��Ұ벿�֡�
 
        ��벿�֣�����������start��min(midIndex-1,midValue)��Ԫ�ء�
 
        �Ұ벿�֣�����������max(midIndex+1,minValue)��end��Ԫ�ء�
        */
        if (start > end || start < 0 || end > n)
        {
            return false;
        }
        int mid = (end - start) / 2 + start;
        if (A[mid] == mid)
        {
            return true;
        }
        else
        {
            int leftEnd = min(mid - 1, A[mid]);
            int rightStart = max(mid + 1, A[mid]);
            return findMagicIndex(A, n, start, leftEnd) || findMagicIndex(A, n, rightStart, end);
        }
    }
};