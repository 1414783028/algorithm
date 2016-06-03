class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //1.��Ч�Լ��
        /*
          str������.* 
        patternģʽ��*ǰ�������һ���ַ�
        */
          //2.ƥ�����
         /*����s[i]��p[i]��ʾ��iλ�õ���β���ַ���
            1)  s[i],p[i]�����ʱ������P[i+1]��=*����.,��return false
                    			 ���P[i+1]=*��s[i]��p[i+2]�����Ƚ�
            2) s[i],p[i]���ʱ,���p[i+1]=*,����s=xxxxzzzz,p=x*yyyy
                                ���p[i+1]������*ʱ����i++
        */
      if(str==NULL||pattern==NULL)
      {
          return false;
      }
      for(int i=0;i<(int)strlen(str);i++)
      {
          if(str[i]=='.'||str[i]=='*')
          {
              return false;
          }
      }
        for(int i=0;i<(int)strlen(pattern);i++)
        {
            if(pattern[i]=='*'&&(i==0||pattern[i-1]=='*'))
            {
                return false;
            }
        }
      return  expMatch(str,0,pattern,0);
    }
    
    bool expMatch(char* s,int si,char* p,int pi)
    {
       if(pi==(int)strlen(p))
       {
           return si==(int)strlen(s);
       }
        //ע��pֻ�������ַ�����û��*ʱ,Ҫ������p[i]==s[i]����si����Ϊ���һ���ַ�
       if(pi+1==(int)strlen(p)||p[pi+1]!='*')
       {
          return si!=(int)strlen(s)&&(s[si]==p[pi]||p[pi]=='.')
              &&expMatch(s,si+1,p,pi+1);
       }
       /*
       p[i+1]=*,s[i],p[i]���ʱ,����s=xxxxzzzz,p=x*yyyy
       */
        while(si!=(int)strlen(s)&&(s[si]==p[pi]||p[pi]=='.'))
        {
            if(expMatch(s,si,p,pi+2))
            {
                return true;
            }
            si++;
        }
       return expMatch(s,si,p,pi+2);
    }
};