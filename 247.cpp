#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;

const int maxV=30;
//const int INF = 1e9;
map <string,int> nameNum;
int cycle[maxV][maxV];
bool check[maxV];

int name2num(string name)
{
    auto pos=nameNum.find(name);
    if(pos!=nameNum.end()) return pos->second;
    int num=nameNum.size();
    nameNum.insert(make_pair(name,num));
    return num;
}
string num2name(int num)
{
    for(auto pos=nameNum.begin(); pos!=nameNum.end(); ++pos)
        if(pos->second==num) return pos->first;
    return "";
}
void init()
{
    for(int i=0; i<maxV; ++i)
        for(int j=0; j<maxV; ++j)
            cycle[i][j]=0;
    for(int i=0;i<maxV;++i) check[i]=false;
}
void Floyd_Warshall(int n)
{
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(i!=j) cycle[i][j]=(cycle[i][j] || (cycle[i][k] && cycle[k][j]) );
}
int main()
{
    int n,m,setN=1;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        init();
        string n1,n2;
        int N1,N2;
        for(int i=0; i<m; ++i)
        {
            cin>>n1>>n2;
            N1=name2num(n1);
            N2=name2num(n2);
            cycle[N1][N2]=1;
        }

        Floyd_Warshall(n);

        cout<<"Calling circles for data set "<<setN<<":"<<endl;
        setN++;
        for(int i=0; i<n; ++i)
        {
            if(check[i]==false)
            {
                check[i]=true;
                cout<<num2name(i);
                for(int j=0;j<n;j++)
                {
                    if(check[j]==false && cycle[i][j] && cycle[j][i])
                    {
                        cout<<", "<<num2name(j);
                        check[j]=true;
                    }
                }
                cout<<endl;
            }
        }
        nameNum.clear();
    }
    return 0;
}
