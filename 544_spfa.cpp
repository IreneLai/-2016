#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<queue>
using namespace std;
map<string,int> city;
int City2num(const string &c)
{
    auto it=city.find(c);
    if(it!=city.end()) return it->second;
    int num=city.size();
    city.insert(make_pair(c,num));
    return num;
}
int main()
{
    int n,r,INF=1e9,count=1;
    while(cin>>n>>r)
    {
        if(n==0 &&r==0)break;
        vector<map<int,int>> adj(n);
        vector<int>f(n,0);
        vector<bool>inQueue(n,false);
        string u,v;
        int ui,vi;
        int w;
        for(int i=0; i<r; ++i)
        {
            cin>>u>>v>>w;
            ui=City2num(u);
            vi=City2num(v);
            adj[ui].insert(make_pair(vi,w));
            adj[vi].insert(make_pair(ui,w));
        }
        cin>>u>>v;
        ui=City2num(u);
        vi=City2num(v);
        queue<int>q;
        q.push(ui);
        inQueue[ui]=true;
        f[ui]=INF;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            inQueue[cur]=false;
            int flow=0;
            for(auto pos=adj[cur].begin(); pos!=adj[cur].end(); ++pos)
            {
                flow=min(f[cur],pos->second);
                if(flow>f[pos->first])
                {
                    f[pos->first]=flow;
                    if(pos->first!=vi && !inQueue[pos->first])
                    {
                        q.push(pos->first);
                        inQueue[pos->first]=true;
                    }
                }
            }
        }
        cout<<"Scenario #"<<count<<endl;
        cout<<f[vi]<<" tons"<<endl<<endl;
        count++;
        for(int i=0; i<n; i++) adj[i].clear();
        city.clear();
        f.clear();
        inQueue.clear();
    }
    return 0;
}
