#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int dist[105][105];
const int INF = 1e9;
void init(int n)
{
    for(int i=1; i<=n; ++i)
        for(int j=0; j<=n; j++)
            dist[i][j]=(i==j)?0:INF;
}
void Floyd_Warshall(int n)
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main()
{
    int n;
    while(cin>>n)
    {
        init(n);
        string str;
        for(int i=2; i<=n; ++i)
        {
            for(int j=1; j<i; j++)
            {
                cin>>str;
                if(str!="x")
                {
                    stringstream ss;
                    ss<<str;
                    ss>>dist[i][j];
                    dist[j][i]=dist[i][j];
                }
            }
        }

        Floyd_Warshall(n);

        int min,tmp;
        for(int i=1; i<=n; i++)
        {
            tmp=0;
            min=INF;
            for(int j=1; j<=n; j++)
            {
                tmp = max(tmp,dist[i][j]);
            }
            if(tmp<min) min=tmp;
        }
        cout<<min<<endl;
    }
    return 0;
}
