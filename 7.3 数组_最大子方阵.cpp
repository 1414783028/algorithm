class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        //�κ�һ������·�(�����Լ�)1�ĸ�����������bottom[i][j]
        //�κ�һ������ұ�(�����Լ�)1�ĸ�����������right[i][j]
        //����ֱ����Ϻ��������
        //������������ɫ�Ƿ���ͬΪʱ,���һ�������k���ж�1�����Ƿ�Ϊk��Ϊ0��
        vector<vector<int> > bottom = mat ,right = mat;
        for(int i=n-1;i>=0;i--)
        {
           if(mat[n-1][i]==1)
           {
               bottom[n-1][i] =  1;
           }
           if(mat[i][n-1]==1)
           {
               right[i][n-1] = 1;
           }
        }
         
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
               if(mat[i][j]==1)
               {
                   bottom[i][j]= bottom[i+1][j]+1;
                   right[i][j]= right[i][j+1]+1;
               }
               else
               {
                   bottom[i][j]= bottom[i+1][j];
                   right[i][j]= right[i][j+1];
               }
            }
        }
         
        int len = 0;
        int squreLen = 0;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
          {
              for(int k=j;k<n;k++)
              {
                  if(mat[i][j]==0)
                  {
                      squreLen = 0;
                  }
                  else
                  {
                      squreLen = k-j;
                  }
                   
                  if( bottom[i][j]>=squreLen && right[i][j]>=squreLen
                     &&  (bottom[i][j]-bottom[i][k]) ==squreLen
                     && (right[i][j]-right[k][j]) == squreLen )
                    {
                        len = max(len,k-j+1);
                    } 
              }
           }
        }
        return len;
    }
};