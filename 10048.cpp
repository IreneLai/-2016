#include<iostream>
using namespace std;
int dist[105][105];
const int INF=1e9;
void init(int C)
{
    for(int i=1; i<=C; ++i)
        for(int j=1; j<=C; ++j)
            dist[i][j]=(i==j)?0:INF;
}
void Floyd_Warshall(int C)
{
    for(int k=1; k<=C; ++k)
    {
        for(int i=1; i<=C; ++i)
        {
            for(int j=1; j<=C; ++j)
            {
                if( dist[i][k]!=INF && dist[k][j]!=INF )
                    dist[i][j]=min(max(dist[i][k],dist[k][j]),dist[i][j]);
            }
        }
    }
}
int main()
{

    int C,S,Q,c1,c2,d,count=1,flag=0;
    while(cin>>C>>S>>Q)
    {
        if(C==0&&S==0&&Q==0) break;
        if(flag) cout<<endl;
        flag=1;
        init(C);
        for(int i=0; i<S; ++i)
        {
            cin>>c1>>c2>>d;
            dist[c1][c2]=d;
            dist[c2][c1]=d;
        }
        cout<<"Case #"<<count<<endl;
        count++;

        Floyd_Warshall(C);

        while(Q--)
        {
            cin>>c1>>c2;
            if(dist[c1][c2]==INF) cout<<"no path"<<endl;
            else cout<<dist[c1][c2]<<endl;
        }
    }
    return 0;
}
