#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

struct Edge
{
    int u=0,v=0;
    double d=0.0;
    bool operator < (const Edge &e) const
    {
        return d<e.d;
    }
};
struct Vertice
{
    int x=0,y=0,root=0;
};
vector <Edge> eg;
vector <Vertice> vt;
void Union(Edge &e)
{
    int r1=vt[e.u].root,r2=vt[e.v].root;
    int minR=min(r1,r2);
    for(int i=0; i<vt.size(); ++i)
    {
        if(vt[i].root==r1 || vt[i].root==r2)
        {
            vt[i].root=minR;
        }
    }
}
double Dis(Vertice &a , Vertice &b)
{
    int num=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    double dis=sqrt(num);
    return dis;
}
int main()
{
    int caseN=0,S,P;
    scanf("%d",&caseN);
    while(caseN--)
    {
        scanf("%d %d",&S,&P);
        for(int i=0; i<P; ++i)
        {
            Vertice vtmp;
            Edge etmp;
            scanf("%d %d",&vtmp.x,&vtmp.y);
            vtmp.root=vt.size();
            for(int j=0; j<vt.size(); ++j)
            {
                etmp.u=j;
                etmp.v=vt.size();
                etmp.d=Dis(vtmp,vt[j]);
                eg.push_back(etmp);
            }
            vt.push_back(vtmp);
        }
        sort(eg.begin(),eg.end());

        int total=0;
        double ans=0.0;
        for(int i=0; i<eg.size(); ++i)
        {
            if(vt[eg[i].u].root!=vt[eg[i].v].root)
            {
                ans=eg[i].d;
                Union(eg[i]);
                total++;
                if(total==(P-S)) break;
            }
        }
        printf("%.2f\n",ans);

        eg.clear();
        vt.clear();
    }

    return 0;
}
