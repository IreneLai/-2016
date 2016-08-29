#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topological_sort(int v,vector <bool> &visit,stack <int> & stk,vector <int> adjList[])
{
    visit[v]=true;
    for(auto pos=adjList[v].begin();pos!=adjList[v].end();++pos)
    {
        if(visit[*pos]==false)
            topological_sort(*pos,visit,stk,adjList);
    }
    stk.push(v);
}
int main()
{
    int n,m,u,v;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        vector <bool> visit (n+1,false);
        vector <int>  adjList [n+1];
        stack <int> stk;
        while(m--)
        {
          cin>>u>>v;
          adjList[u].push_back(v);
        }
        for(int i=1;i<=n;++i)
        {
            if(visit[i]==false)
                topological_sort(i,visit,stk,adjList);
        }
        while(!stk.empty())
        {
            cout<<stk.top()<<" ";
            stk.pop();
        }
        cout<<endl;
        visit.clear();
        for(int i=0;i<=n;++i) adjList[i].clear();
    }
    return 0;
}
