#include<iostream>
#include<queue>
#include<sstream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

vector <char> str (26,'\0');
int cnt[26], adjMatrix[26][26], used[26];

void topological_sort(int curIND ,const int total) //DFS
{
    if(curIND==total)
    {
        for(int i=0; i<curIND; ++i) cout<<str[i];
        cout<<endl;
        return;
    }
    for(int i=0; i<26; ++i)
    {
        if(cnt[i]==1 && used[i]==0)
        {
            for(int j=0; j<26; ++j)
            {
                if(adjMatrix[i][j]==1 && used[j]==1) return ;
                //檢查有無符合限制順序
            }
            used[i]=1;
            str[curIND]=i+'a';
            topological_sort(curIND+1,total);
            used[i]=0;
        }
    }
}
int main()
{
    string line,cnstr;
    stringstream ss;
    bool flag=false;
    while(getline(cin,line))
    {
        memset(cnt,0,sizeof(cnt));
        memset(used,0,sizeof(used));
        memset(adjMatrix,0,sizeof(adjMatrix));
        str.clear();

        ss.clear();
        ss<<line;
        char u,v;
        int count=0;

        while(ss>>u)
        {
            cnt[u-'a']=1;
            count++;
        }

        if(flag) cout<<endl;
        flag=true;

        ss.clear();
        getline(cin,cnstr);
        ss<<cnstr;
        while(ss>>u>>v)
        {
            adjMatrix[u-'a'][v-'a']=1;
        }
        topological_sort(0,count);
    }
    return 0;
}
