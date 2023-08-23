/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
struct node{
    int val;
    int dep;
    vector<int>ro;
}tr[105];
int dfs(int pos,int fa){
    int ans=0;
    tr[pos].dep=tr[fa].dep+1;
    for(int to:tr[pos].ro){
        if(to==fa)continue;
        ans+=dfs(to,pos);
    }
    ans+=tr[pos].dep*tr[pos].val;
    return ans;
}
int main(){
    n=read();
    for(int i = 1,u,v,w;i<=n;i++){
        w=read(),u=read(),v=read();
        tr[i].val=w;
        if(u) tr[i].ro.push_back(u),tr[u].ro.push_back(i);
        if(v) tr[i].ro.push_back(v),tr[v].ro.push_back(i);
    }
    tr[0].dep=-1;
    int ANS=2147483647;
    for(int i = 1;i<=n;i++){
        ANS=min(ANS,dfs(i,0));
    }
    cout<<ANS;
    return 0;
}