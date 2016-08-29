#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int maxN=105;
int dist[maxN][maxN];
const int INF = 1e9;
set<int> s;

void init()
{
    for(int i=0; i<maxN; ++i)
        for(int j=0; j<maxN; ++j)
            dist[i][j]=(i==j)?0:INF;
}
void Floyd_warshall(int M,int N)
{
    for(int k=M; k<=N; ++k)
        for(int i=M; i<=N; ++i)
            for(int j=M; j<=N; ++j)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
void GetMinMax(int &minV,int &maxV)
{
    minV=INF;
    maxV=0;
    for(auto pos=s.begin(); pos!=s.end(); ++pos)
    {
        if(*pos<minV) minV=*pos;
        if(*pos>maxV) maxV=*pos;
    }
}
int main()
{
    int a,b,maxV,minV,count=1;
    while(cin>>a>>b)
    {
        if(a==0 && b==0) break;
        init();
        dist[a][b]=1;
        s.insert(a);
        s.insert(b);
        while(cin>>a>>b)
        {
            if(a==0 && b==0) break;
            s.insert(a);
            s.insert(b);
            dist[a][b]=1;
        }

        GetMinMax(minV,maxV);
        Floyd_warshall(minV,maxV);

        int total=0,tmp=0;
        for(int i=minV; i<=maxV; ++i)
            for(int j=minV; j<=maxV; ++j)
                if(dist[i][j]<INF && dist[i][j]!=0) total+=dist[i][j],tmp+=1;

        double ans=(double)total/tmp;
        printf("Case %d: average length between pages = %.3f clicks\n",count,ans);
        count++;
        s.clear();
    }
    return 0;
}
