/*
���������ַ��������д����
ȷ������һ���ַ������ַ��������к�
�ܷ�����һ���ַ�����
����涨��СдΪ��ͬ�ַ���
�ҿ����ַ����ص�ո�
*/
class Same {
public:
    bool checkSam(string stringA, string stringB) {
    if(stringA.size() != stringB.size()){
        return false;
    } 
    int str[256] = {0};

    for(int i = 0; i < stringA.size(); i++){
        str[stringA[i]]++;
        str[stringB[i]]--;
    }

    for(int i = 0;i<256;i++){
        if(str[i]!= 0) return false;
    }
    return true;
}
};