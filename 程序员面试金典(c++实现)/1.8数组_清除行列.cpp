/*
���дһ���㷨����MxN������ĳ��Ԫ��Ϊ0���������ڵ����������㡣
*/
/*
*�˷����ռ临�Ӷ�O(m+n)��ʱ�临�Ӷ�O(m*n)�������ҵ���Ҫ��Ϊ0���к��кţ�
��¼�ھ���row��col�У�����Ҫ��Ϊ0���Ϊ1����֮��Ϊ0���������
*/
class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        vector<bool> row(n),col(n);
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                
                if(mat[i][j]==0)
                {
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                
              if(row[i]||col[j])
              {
                  mat[i][j] = 0;
              }
            }
        }
        return mat;
    }
};