#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct Edge
{
    int u,v;
};
map <char,int> m;
int char2num(const char &c)
{
    if(m.find(c)!=m.end()) return m.find(c)->second;
    int num=m.size();
    m.insert(make_pair(c,num));
    return num;
}
char num2char(int num)
{
    for(auto pos=m.begin();pos!=m.end();++pos)
    {
        if(pos->second==num) return pos->first;
    }
    return '\0';
}
void topological_sort(int v,vector <bool> &visit,stack <int> &stk,vector<int>adjList[])
{
    visit[v]=true;
    for(auto pos =adjList[v].begin();pos!=adjList[v].end();++pos)
    {
        if(visit[*pos]==false)
            topological_sort(*pos,visit,stk,adjList);
    }
    stk.push(v);
}
int main()
{
    string str;
    vector <string> dic;
    vector <Edge> eg;
    while(cin>>str && str!="#")
    {
        dic.push_back(str);
    }
    string s1,s2;
    for(int i=1; i<dic.size(); ++i)
    {
        s1=dic[i-1],s2=dic[i];
        int minlen=min(s1.size(),s2.size());
        for(int j=0; j<minlen; ++j)
        {
            if(s1[j]!=s2[j])
            {
                Edge e;
                e.u=char2num(s1[j]);
                e.v=char2num(s2[j]);
                eg.push_back(e);
                break;
            }
        }
    }
    int size_=m.size();
    vector <int> adjList[size_];
    stack<int> stk;
    vector <bool> visit(size_,false);
    int u,v;
    for(int i=0;i<eg.size();++i)
    {
        u=eg[i].u;
        v=eg[i].v;
        auto it= find(adjList[u].begin(),adjList[u].end(),v);
        if(it == adjList[u].end()) adjList[u].push_back(v);
    }
    //topological sort
    for(int i=0;i<size_;++i)
    {
        if(visit[i]==false)
            topological_sort(i,visit,stk,adjList);
    }
    while(!stk.empty())
    {
        char ans=num2char(stk.top());
        cout<<ans;
        stk.pop();
    }
    cout<<endl;
    return 0;
}
