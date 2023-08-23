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
vector<int>ro[100005];
int dep[100005];
long double dfs(int pos,int fa){
    long double ans=0;
    dep[pos]=dep[fa]+1;
    for(int to:ro[pos]){
        if(to==fa)continue;
        ans+=dfs(to,pos);
    }
    ans+=1.0/dep[pos];
    return ans;
}
int main(){
    n=read();
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    long double ans = dfs(1,0);
    printf("%.12Lf",ans);
    return 0;
}