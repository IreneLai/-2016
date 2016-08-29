#include<iostream>
#include<vector>
using namespace std;
int dist[1005];
const int INF=1e9;
struct Edge
{
    int u,v,w;
};
void init(int n)
{
    for(int i=0;i<n;++i)
        dist[i]=INF;
    dist[0]=0;
}
int main()
{
    int c;
    while(cin>>c)
    {
        int n,m;
        while(c--)
        {
            vector<Edge> edge;
            bool isNCYCLE=false;
            cin>>n>>m;
            init(n);
            for(int i=0;i<m;++i)
            {
                Edge e;
                cin>>e.u>>e.v>>e.w;
                edge.push_back(e);
            }
            //Bellman Ford
            for(int i=0;i<(n-1);++i)
                for(int j=0;j<m;++j)
                    dist[edge[j].v]=min(dist[edge[j].v],dist[edge[j].u]+edge[j].w);

            for(int i=0;i<m;i++)
                if(dist[edge[i].v]>dist[edge[i].u]+edge[i].w)
                    {isNCYCLE=true;break;}

            if(isNCYCLE) cout<<"possible"<<endl;
            else cout<<"not possible"<<endl;
            edge.clear();
        }
    }
    return 0;
}
