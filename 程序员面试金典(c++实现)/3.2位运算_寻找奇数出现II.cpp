#include<iostream>
#include<vector>
using namespace std;
class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
        // write code here
        //������������ε�a,b
        //����ec=0����arr������򣬽��Ϊec=a^b
        //��Ϊa��b���죬����ec������0����ec�ĵ�kλΪ1
        //�������ec1 = 0;��arr�е�kλΪ1��ֵ����������򣬽��ec1 = a��ec =b
        //ͨ��ec^ec1��ñ���һ����
        int eO = 0, eOhasOne = 0;
        for (int curNum : arr) {
            eO ^= curNum;
        }
        int rightOne = eO & (~eO + 1);//ȡ�����1�任����
        for (int cur : arr) {
            if ((cur & rightOne) != 0) {
                eOhasOne ^= cur;
            }
        }
        int small = Math.min(eOhasOne, (eO ^ eOhasOne));
        int big = Math.max(eOhasOne, (eO ^ eOhasOne));
        return new int[] { small, big };
    }
};