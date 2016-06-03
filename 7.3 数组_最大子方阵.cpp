class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
      
        if(n == 0) return 0;
        vector<vector<int> > matA = mat;//������·�����1�ĸ���
        vector<vector<int> > matB = mat;//������ҷ�����1�ĸ���
        vector<vector<int> > matAA = mat;//������·�����0�ĸ���
        vector<vector<int> > matBB = mat;//������ҷ�����0�ĸ���
        //����ֱ����Ϻ��������
        //����ʱ,���һ��������߳����ж�1����0�ĸ����Ƿ�Ϊ�߳�����
        int i,j;
        int len = 0;
        int wide;
        for(i=n-1;i>=0;--i){
            for(j=n-1;j>=0;--j){
                if(mat[i][j] == 0){
                    matA[i][j] = 0;
                    matB[i][j] = 0;
                    if(i == n-1){
                        matAA[i][j] = 1;
                    }else{
                        matAA[i][j] = matAA[i+1][j]+1;
                    }
                    if(j == n-1){
                        matBB[i][j] = 1;
                    }else{
                        matBB[i][j] = matBB[i][j+1]+1;
                    }
                }else {
                    if(i == n-1){
                        matA[i][j] = 1;
                    }else{
                        matA[i][j] = matA[i+1][j]+1;
                    }
                    if(j == n-1){
                        matB[i][j] = 1;
                    }else{
                        matB[i][j] = matB[i][j+1]+1;
                    }
                    matAA[i][j] = 0;
                    matBB[i][j] = 0;
                }
            }
        }
       for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(mat[i][j] == 0){
                    wide = min(matAA[i][j],matBB[i][j]);
                    while(wide>0){
                        if(matAA[i][j+wide-1] >= wide && matBB[i+wide-1][j] >= wide){
                            len = len<wide?wide:len;
                        }
                        wide--;
                    }
                }else{
                    wide = min(matA[i][j],matB[i][j]);
                    while(wide>0){
                        if(matA[i][j+wide-1] >= wide && matB[i+wide-1][j] >= wide){
                            len = len<wide?wide:len;
                        }
                        wide--;
                    }
                }
            }
        }
        return len;
    }
};
��ӱʼ�
