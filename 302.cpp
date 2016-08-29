#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>
using namespace std;
const int maxV=2000;
struct Edge
{
    int u,v,id;
    Edge(int u=0,int v=0,int id=0):u(u),v(v),id(id) {}
    bool operator < (const Edge & e) const
    {
        return id<e.id;
    }
};
map <int,bool> visit;
deque <int> q;
vector <Edge> eg;
map <int,int> degree;
int & Degree(int v)
{
    auto it = degree.find(v);
    if(it == degree.end())
        degree.insert(make_pair(v,0));
    return degree.find(v)->second;
}
bool check()
{
    for(auto pos=visit.begin(); pos!=visit.end(); ++pos)
        if(pos->second==false) return false;
    return true;
}
void DFS(int u)
{
    for(auto pos=eg.begin(); pos!=eg.end(); ++pos)
    {
        if(!visit[pos->id] && (pos->u==u||pos->v==u))
        {
            visit[pos->id]=true;
            if(pos->v==u) swap(pos->v,pos->u);
            DFS(pos->v);
            q.push_front(pos->id);
        }
    }
}
int main()
{
    int count=0,u,v,id;
    while(true)
    {
        count=0;
        int start;
        visit.clear();
        eg.clear();
        degree.clear();

        while(cin>>u>>v)
        {
            if(u==0 && v==0)break;
            cin>>id;
            if(u>v) swap(u,v);
            Edge e(u,v,id);
            if(count == 0 ) start=e.u;
            eg.push_back(e);
            visit.insert(make_pair(id,false));
            Degree(u)++;
            Degree(v)++;
            count++;
        }
        if(count==0) break;

        bool euler=true;
        for(auto pos=degree.begin(); pos!=degree.end(); ++pos)
            if(pos->second%2)
            {
                euler=false;
                break;
            }
        if(!euler) cout<<"Round trip does not exist.";
        else
        {
            sort(eg.begin(),eg.end());
            DFS(start);
            count=0;
            while(!q.empty())
            {
                count++;
                cout<<q.front();
                if(count<eg.size()) cout<<" ";
                q.pop_front();
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}
