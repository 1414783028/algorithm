class Solution {
public:
	/**
	 *	���������󳤶����Ŀ����������鳤��
	 *	arr����������
	 *	���أ����Ŀ�����������ĳ���
	 */
	int getMaxLength(vector<int> arr, int len) {
        //������������û���ظ�(һ�����־�û�б�Ҫ���Ҽ�������)
        //���ֵ-��Сֵ+1 =  ����
        int res = 0;
        map<int,int>help;
        for(int i=0;i<len;i++)
        {
            int max=0x80000000;  
            int min=0x7fffffff;
            for(int j=i;j<len;j++)
            {
               if(help[arr[j]]!=0)
                {
                    break;
                }
                help[arr[j]]++;
                max = max>arr[j]?max:arr[j];
                min = min<arr[j]?min:arr[j];
                if(max-min == (j-i))
                {
                   res = res>(max-min+1)?res:(max-min+1);
                }
            }
            help.clear();
        }
       return res;
    }
};