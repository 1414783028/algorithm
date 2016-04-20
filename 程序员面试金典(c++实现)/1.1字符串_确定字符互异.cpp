
/*
1����ϣ������char�����ж��ظ�����hash������㣬ֻ��Ҫ256��bool���ͼ��ɣ�
O(n)��ʱ�䣨��ʵֻҪ�ж�ǰ257��������O(1)������ԭ��
2��������ôֻ��������forѭ��������ʱ�临�Ӷ�ΪO(n*n)��
���Ǹ��ݳ���ԭ��û��Ҫ������N��ֻ��Ҫ������ǰ257�͹��ˣ�
���N<257�ͱ�����N������ʱ�临�Ӷ���ʵΪO(1)!!!
3�������Ȼ��ĿҪ����ʹ�ö���ռ䣬�������б�û��const�����ã�
��ô�Ϳ��Զ��ַ�������Ȼ�����жϣ���ҪO��nlogn)����
Ȼ���ٱ���һ��O(n)����ʵҲû��Ҫȫ������ֻ��ǰ257����ͬ����ԭ��
4��Parition���ڿ��������partition�����Ա���������ظ���
Ҳ����ÿ��partition֮���жϻ�׼keyԪ��������Ԫ���Ƿ���ͬ����ͬ�򷵻�false��
��ͬ�ٽ�����һ��partition.ʱ�临�Ӷ�Ҳ��O(nlongn)����Ҫ�������ٶȿ졣
*/
class Different {   
	bool quick_check(string &str,int low,int high)
	{

			int first = low,last = high;

			char key = str[first];

			if (low>=high)

				return true;

			while(first<last){

				while(first <last && str[last] >= key)

					last--;            

				str[first] = str[last];

				while(first<last && str[first] <= key)

					first++;

				str[last] = str[first];

			}

			str[first] = key;

			if (first>low && str[first] == str[first-1])

				return false;

			if (first<high && str[first] == str[first+1])

				return false;

			return quick_check(str,low,first-1) && quick_check(str,first+1,high);

		}

	public:

		bool checkDifferent(string iniString) 
		{

			// write code here

			return quick_check(iniString,0,iniString.size()-1);

		}
};