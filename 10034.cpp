#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Vertice
{
    int ver=0;
    double x=0.0,y=0.0;
    int root=0;
};
struct Edge
{
    double value=0.0;
    int u=0,v=0;
    bool operator <(const Edge &e)const
    {
        return value<e.value;
    }
};
vector<Edge> eg;
vector<Vertice> vt;
double Distance(Vertice &a,Vertice &b)
{
    double dis=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    dis=sqrt(dis);
    return dis;
}
bool Union(int r1,int r2)
{
    int minR=min(r1,r2);
    for(int i=0;i<vt.size();++i)
    {
        if(vt[i].root==r1 || vt[i].root==r2)
            vt[i].root=minR;
    }
}
int main()
{
    int caseN=0;
    cin>>caseN;
    while(caseN--)
    {
        int num=0;
        cin>>num;
        for(int i=0; i<num; ++i)
        {
            Vertice v;
            cin>>v.x>>v.y;
            v.root=i;
            v.ver=i;
            vt.push_back(v);
            for(int j=0; j<i; ++j)
            {
                Edge e;
                double dis=Distance(vt[i],vt[j]);
                e.u=j;
                e.v=i;
                e.value=dis;
                eg.push_back(e);
            }
        }

        sort(eg.begin(),eg.end());
        double ans=0.00;
        int total=0;
        for(int i=0; i<eg.size(); ++i)
        {
            int v1=eg[i].u,v2=eg[i].v;
            if(vt[v1].root!=vt[v2].root)
            {
                Union(vt[v1].root,vt[v2].root);
                ans+=eg[i].value;
                total++;
                if(total>=vt.size())break;
            }
        }
        printf("%.2f\n",ans);

        if(caseN!=0) cout<<endl;
        eg.clear();
        vt.clear();
    }
    return 0;
}
