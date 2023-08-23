/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
/* #include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int fa[100005][25],dep[100005];
long long val[100005][25],val_2[100005][25];
vector<int>ro[5000005];
void dfs(int now,int fat){
    dep[now]=dep[fat]+1;
    fa[now][0]=fat;
    for(int i = 1;i<=19;i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
        a[now]
    }
    for(int to:ro[now]){
        if(to==fat)continue;
        dfs(to,now);
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        val[i][0]=read();
        val_2[i][0]=val[i][0]*val[i][0];
    }
    for(int i = 1;i<n;i++){
        fa[i][0]=read();
        ro[fa[i][0]].push_back(i);
    }
    dfs(1,0);
    return 0;
} */

#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,sep;
int val[100005];
long long sum_val_2[100005];
long long f[100005][500];
int fa[100005];
int dep[100005];
int num[100005];
int idx[100005];
vector<int>son[100005];
void dfs1(int pos,int fa){
    dep[pos]=dep[fa]+1;
    idx[pos]=++num[dep[pos]];
    sum_val_2[pos]=sum_val_2[fa]+1LL*val[pos]*val[pos];
    for(int nex:son[pos]){
        if(nex==fa)continue;
        dfs1(nex,pos);
    }
}
long long dfs2(int x,int y){
    if(x==y)return sum_val_2[x];
    if(num[dep[x]]<sep){
        if(f[x][idx[y]])return f[x][idx[y]];
        else return f[x][idx[y]]=dfs2(fa[x],fa[y])+1LL*val[x]*val[y];
    }else return dfs2(fa[x],fa[y])+1LL*val[x]*val[y];
}
int main(){
    n=read(),m=read();
    sep=__builtin_sqrt(n);
    for(int i = 1;i<=n;i++) val[i]=read();
    for(int i = 2;i<=n;i++){
        fa[i]=read();
        son[fa[i]].push_back(i);
    }
    dfs1(1,0);
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        printf("%lld\n", dfs2(x,y));
    }
    return 0;
}