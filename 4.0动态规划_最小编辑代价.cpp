#include<iostream>
#include<vector>
using namespace std;
class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        /*
        (1) ����S[i] == T[j], ��ʱǰi �C 1��j �C 1λ���Ѿ������ˣ��ⲿ�ֿ϶�Ҫ���ٿ۷֡�������������ٵĿ۷���f(i-1,j-1)
        (2) �ͣ�1�����ƣ�S[i]��T[j]��������������ٵĿ۷���f(i -1, j �C 1) + 1
        (3) S��ǰiλ��T��ǰ��j �C 1��λ�Ѿ������ˣ��ⲿ�ֿ۷�ҲҪ���١�������������ٵĿ۷���f(i,j-1) + 1
        (4) S��ǰ(i-1)λ�Ѿ���T��ǰjλ�����ˣ��ⲿ�ֿ۷�Ҫ���١�������������ٵĿ۷���f(i,j-1) + 1
        
        */
        if(n <= 0 || m <= 0)
            return 0;
        vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i < n + 1; i++)
            dp[i][0] = c1 * i;
        for(int j = 1; j < m + 1; j++)
            dp[0][j] = c0 * j;
         
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j - 1] + c2;
                dp[i][j] = min(dp[i][j - 1] +  c0, dp[i][j]);
                dp[i][j] = min(dp[i - 1][j] +  c1, dp[i][j]);
            }
        }
        return dp[n][m];
    }
};