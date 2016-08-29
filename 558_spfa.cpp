#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
const int INF = 1e9;
int main()
{
    int caseN,n,m;
    cin>>caseN;
    while(caseN--)
    {
        cin>>n>>m;
        vector <map<int,int> > adjList(n);
        vector <int> inQtimes(n,0);
        vector <int> dist(n,INF);
        int u,v,w;
        while(m--)
        {
            cin>>u>>v>>w;
            adjList[u].insert(make_pair(v,w));
        }
        int negCycle=false;
        queue <int> q;
        q.push(0);
        dist[0]=0;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(auto pos = adjList[cur].begin(); pos!=adjList[cur].end(); ++pos)
            {
                if(dist[pos->first] > (dist[cur]+ pos->second ) )
                {
                    dist[pos->first] = dist[cur]+ pos->second;
                    inQtimes[pos->first]++;
                    if(inQtimes[pos->first]>(n-1))
                    {
                        negCycle=true;
                        break;
                    }
                    q.push(pos->first);
                }
            }
            if(negCycle) break;
        }
        if(negCycle) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
        for(int i=0;i<n;++i)adjList[i].clear();
        inQtimes.clear();
        dist.clear();
    }
    return 0;
}
