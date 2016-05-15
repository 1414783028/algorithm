#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    //��cur������չ�ĺ��ӽڵ����children
    void extend(string &cur,string &end,set<string> &dict, 
                vector<string> &children,set<string> &visit)
    { 
        string child = cur;
        children.clear();
        char c,t;
        for(int i=0;i<(int)cur.size();i++)
        {
            t = child[i];
            for(c='a';c!='z';c++)
            {
                if(c==t) continue;
                child[i] = c;
                if(( child==end||( dict.find(child)!=dict.end() ))
                   &&visit.find(child)==visit.end())
                {
                   children.push_back(child);
                   visit.insert(child); 
                }
            } 
            child[i] = t;
        }
       
    }
    int ladderLength(string start, string end, set<string> &dict) {
        //��ʽͼ ����������� ����Ҫ���Ƚ���ͼ����  
        if(start==end) return 0;
        queue<string> q;
        q.push(start);
        vector<string> children;//�ӵ�ǰ��������չ���½�㼯��
        set<string> visit;
        string cur;
        int step = 0;
        int curNumber = 1,nextNumber=0;//��ǰ�㻹�н����  ��һ��Ľ����
        while(!q.empty())
        {
            cur = q.front();//��cur��ʼ��չ
            q.pop();
            curNumber--;
            extend(cur,end,dict,children,visit);//�����չ
            nextNumber+=(int)children.size();
            if(curNumber==0)//��ǰ������꣬������һ��
            {
                step++;
                curNumber = nextNumber;
                nextNumber = 0;
            }
            for(vector<string>::iterator it=children.begin();it!=children.end();++it)
            {
                if(*it==end)
                {
                    return step;
                }
                q.push(*it);
            }
        }
       return 0;
    }
};