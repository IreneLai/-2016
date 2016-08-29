#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include <algorithm>
using namespace std;

multimap <string,string> Depend;
multimap <string,string> isDepended;
map <string,int> status;
vector <string> installed;

void getCMD(string line ,vector <string> &cmd)
{
    stringstream ss(line);
    string str;
    while(ss>>str)
    {
        cmd.push_back(str);
    }
}
bool Install(string item ,bool sts)
{
    if(status[item]<=0)
    {
        auto it=Depend.find(item);
        for(int i=0; i<Depend.count(item); ++i)
        {
            Install(it->second,false);
            it++;
        }
        cout<<"   Installing "<<item<<endl;
        int s=(sts)?1:2;
        if(status.count(item)>0) status[item]=s;
        else status.insert(make_pair(item,s));
        installed.push_back(item);
        return true;
    }
    return false;
}
bool Needed(string item)
{
    auto it = isDepended.find(item);
    for(int i=0; i<isDepended.count(item); ++i)
    {
        if(status[it->second])
        {
            return true;
        }
        it++;
    }
    return false;
}
bool Remove(string item , bool sts)
{
    if((sts || status.find(item)->second ==2 ) && !Needed(item))
    {
        if(status.count(item)>0) status[item]=0;
        else status.insert(make_pair(item,0));

        installed.erase(remove(installed.begin(),installed.end(),item),installed.end());
        cout<<"   Removing "<<item<<endl;
        auto it = Depend.find(item);
        for(int i=0; i<Depend.count(item); ++i)
        {
            Remove(it->second,false);
            it++;
        }
        return true;
    }
    return false;
}
int main()
{
    string line;
    vector <string> cmd;
    while(getline(cin,line))
    {
        getCMD(line,cmd);
        cout<<line<<endl;
        if(cmd[0]=="DEPEND")
        {
            for(int i=2; i<cmd.size(); ++i)
            {
                Depend.insert(make_pair(cmd[1],cmd[i]));
                isDepended.insert(make_pair(cmd[i],cmd[1]));
            }
        }
        else if(cmd[0]=="INSTALL")
        {
            if(!Install(cmd[1] ,true))
                cout<<"   "<<cmd[1]<<" is already installed."<<endl;
        }
        else if(cmd[0]=="REMOVE")
        {
            if (status[cmd[1]]<=0)
            {
                cout<<"   "<<cmd[1]<<" is not installed."<<endl;
            }
            else if(!Remove(cmd[1], true))
            {
                cout<<"   "<<cmd[1]<<" is still needed."<<endl;
            }
        }
        else if(cmd[0]=="LIST")
        {
            for(auto pos=installed.begin(); pos!=installed.end(); ++pos)
                cout<<"   "<<*pos<<endl;
        }
        else break;
        cmd.clear();
    }
    return 0;
}
