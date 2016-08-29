#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
struct Edge
{
    int u=0,v=0;
    double d=0.0;
    bool operator<(const Edge &e)const
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
double Dis(Vertice &a,Vertice &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void Union(const Edge & e)
{
    int r1=vt[e.u].root,r2=vt[e.v].root;
    int minR=min(r1,r2);
    for(int i=0; i<vt.size(); ++i)
    {
        if(vt[i].root == r1 || vt[i].root == r2)
        {
            vt[i].root = minR;
        }
    }
}
int main()
{
    int n,x,y,caseN=1;
    while(scanf("%d",&n)==1 && n!=0)
    {
        for(int t=0; t<n; ++t)
        {
            Vertice vtmp;
            Edge etmp;
            scanf("%d %d",&vtmp.x,&vtmp.y);
            vtmp.root=t;
            for(int i=0; i<t; ++i)
            {
                etmp.u=i;
                etmp.v=t;
                etmp.d=Dis(vtmp,vt[i]);
                eg.push_back(etmp);
            }
            vt.push_back(vtmp);
        }

        sort(eg.begin(),eg.end());
        double ans=0.0;
        for(int i=0; i<eg.size(); ++i)
        {
            if(vt[eg[i].u].root!=vt[eg[i].v].root)
            {
                Union(eg[i]);
                ans=eg[i].d;
                if(vt[1].root==0) break;
            }
        }

        printf("Scenario #%d\n",caseN);
        printf("Frog Distance = %.3f\n\n",ans);
        caseN++;
        eg.clear();
        vt.clear();
    }
    return 0;
}
