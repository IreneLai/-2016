#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef pair<string,int> si;
const int INF=1e9;
int main()
{
    int n,r,count=1;
    while(cin>>n>>r)
    {
        if(n==0&&r==0) break;
        string c1,c2;
        int w;
        map <string,int> dis;
        map <string,bool> ok;
        multimap <string,si> adjList;
        while(r--)
        {
            cin>>c1>>c2>>w;
            adjList.insert(make_pair(c1,si(c2,w)));
            adjList.insert(make_pair(c2,si(c1,w)));
            dis[c1]=0;
            dis[c2]=0;
            ok[c1]=false;
            ok[c2]=false;
        }
        string s,t;
        cin>>s>>t;
        dis[s]=INF;
        while(n--)
        {
            string cur("*");
            int maxW=0;
            for(auto pos=dis.begin(); pos!=dis.end(); ++pos)
            {
                if(!ok[pos->first] && pos->second>maxW)
                {
                    maxW=pos->second;
                    cur=pos->first;
                }
            }
            if(cur=="*"||cur==t) break;
            ok[cur]=true;
            int num=adjList.count(cur);
            auto pos=adjList.find(cur);
            for(int i=0; i<num; ++i)
            {
                si now=pos->second;
                if(!ok[now.first])
                    dis[now.first]=max(min(dis[pos->first],now.second),dis[now.first]);
                pos++;
            }
        }
        cout<<"Scenario #"<<count<<endl;
        cout<<dis[t]<<" tons"<<endl<<endl;
        count++;
        dis.clear();
        ok.clear();
        adjList.clear();
    }
    return 0;
}
