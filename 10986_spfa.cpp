#include<queue>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    int caseN=0;
    cin>>caseN;
    int count=1;
    while(caseN--)
    {
        int n,m,S,T,INF=1e9;
        cin>>n>>m>>S>>T;
        vector <map<int,int>> adj(n);
        vector <bool> inQueue(n,false);
        vector <int> dis(n,INF);
        //build adjList
        int u,v,w;
        for(int i=0; i<m; ++i)
        {
            cin>>u>>v>>w;
            auto it=adj[u].find(v);
            if(it!=adj[u].end() && it->second >w)
            {
                it->second =w;
                it=adj[v].find(u);
                it->second=w;
            }
            else
            {
                adj[u].insert(make_pair(v,w));
                adj[v].insert(make_pair(u,w));
            }
        }
        queue <int> q;
        q.push(S);
        dis[S]=0;
        inQueue[S]=true;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            inQueue[cur]=false;
            for(auto pos=adj[cur].begin(); pos!=adj[cur].end(); ++pos)
            {
                if(dis[pos->first]>dis[cur]+pos->second)
                {
                    dis[pos->first]=dis[cur]+pos->second;
                    if(!inQueue[pos->first] && pos->first!=T)
                    {
                        inQueue[pos->first]=true;
                        q.push(pos->first);
                    }
                }
            }
        }
        cout<<"Case #"<<count<<": ";
        if(dis[T]<INF) cout<<dis[T]<<endl;
        else cout<<"unreachable"<<endl;
        count++;
        //clear
        for(int i=0; i<n; ++i) adj[i].clear();
        inQueue.clear();
        dis.clear();
    }
    return 0;
}
