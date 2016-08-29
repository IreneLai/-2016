#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
bool G[26][26];
int p[26];
int outDegree[26];
int inDegree[26];
void init()
{
    for(int i=0;i<26;++i)
    {
        for(int j=0;j<26;++j)
        {
            G[i][j]=false;
        }
        outDegree[i]=0;
        inDegree[i]=0;
        p[i]=i;
    }
}
bool isConnect()
{
    int flag=-1;
    for(int i=0;i<26;++i)
    {
        for(int j=0;j<26;++j)
        {
            if(G[i][j])
            {
                p[i]=min(p[i],p[j]);
                p[j]=min(p[i],p[j]);
            }
            if(G[i][j] &&flag==-1 ) flag=p[i];
            if(G[i][j] && p[i]!=flag) return false;
        }
    }
    return true;
}
bool isEuler()
{
    if(!isConnect()) return false;
    int start=0,end=0;
    for(int i=0;i<26;++i)
    {
        if((outDegree[i]-inDegree[i])==1) start++;
        else if((inDegree[i]-outDegree[i])==1) end++;
        else if(inDegree[i]!=outDegree[i]) return false;
    }
    if(start == 0 && end ==0) return true;
    if(start == 1 && end ==1 ) return true;
    return false;
}
int main()
{
    int caseN=0,n,u,v;
    string pwd;
    cin>>caseN;
    while(caseN--)
    {
        cin>>n;
        init();
        for(int i=0;i<n;++i)
        {
            cin>>pwd;
            u=pwd[0]-'a';
            v=pwd[pwd.size()-1]-'a';
            G[u][v]=true;
            outDegree[u]++;
            inDegree[v]++;
        }
        if(isEuler())
            cout<<"Ordering is possible."<<endl;
        else cout<<"The door cannot be opened."<<endl;
    }
    return 0;
}
