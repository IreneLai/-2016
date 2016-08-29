#include<iostream>
#include<vector>
using namespace std;
struct Edge
{
    int p,q;
};
int main()
{
    int count=1;
    int n,s;
    int dis[105];
    vector<Edge> edge;
    while(cin>>n)
    {
        if(n==0) break;
        cin>>s;
        Edge e;
        while(cin>>e.p>>e.q)
        {
            if(e.p==0 && e.q==0) break;
            edge.push_back(e);
        }
        for(int i=0; i<=n; ++i) dis[i] = 0;

        //Bellman Ford
        for(int i=0; i<(n-1); ++i)
        {
            for(int j=0; j<edge.size(); ++j)
            {
                if( dis[edge[j].p]>0 || edge[j].p==s )
                    dis[edge[j].q] = max(dis[edge[j].q],dis[edge[j].p] + 1);
            }
        }

        int longestPath=dis[1],ind=1;
        for(int i=1; i<=n; ++i)
        {
            if(dis[i]>longestPath)
            {
                longestPath = dis[i];
                ind = i;
            }
        }
        cout<<"Case "<<count<<": The longest path from "<<s<<" has length "
            <<longestPath<<", finishing at "<<ind<<"."<<endl<<endl;
        count++;
        edge.clear();
    }
    return 0;
}

