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
int n,m,r,p;
int val[100005],fat[100005],dep[100005],son[100005],top[100005],sz[100005];
vector<int>ro[100005];
void dfs1(int now,int fa){
    fat[now]=fa,dep[now]=dep[fa]+1,sz[now]=1;
    
}
int main(){
    n=read(),m=read(),r=read(),p=read();
    for(int i = 1;i<=n;i++) val[i]=read();
    for(int i = 1,x,y;i<n;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
    }
    dfs1(1,0);
    return 0;
}