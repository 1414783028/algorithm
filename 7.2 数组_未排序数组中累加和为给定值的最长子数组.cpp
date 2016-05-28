class maxIsSomeValue {
public:
	/*
	
	**˼·��**sum[i]+k = sum[j],��j-(i+1)�ĳ��ȼ�Ϊ����
	��������һ����ϣ���¼�ۼӺ�sum[i]������ֵ�λ��
	*/
	int maxlen(int arr[], int k,int n){
		map<int, int> m;
		map<int, int>::iterator it;
		m[0] = -1;
		int len = 0;
		int sum =0;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			it = m.find(sum - k);
			if (it!=m.end()){
				len = max(i-m[sum - k], len);
			}
			if (it == m.end()){
				m[sum] = i;
			}
		}
		return len;
	}
}