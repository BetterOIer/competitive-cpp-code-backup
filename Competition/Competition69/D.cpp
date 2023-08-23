/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,q;
long long g[3005][3005];
long long tmp[3005][3005];
long long vis[3005];
void dfs(long long pos,long long ori){
    vis[pos]=true;
    for(long long i = 1;i<=n;i++){
        if(i==pos)continue;
        if(vis[i])continue;
        if(!g[pos][i])continue;
        tmp[ori][i]=1;
        dfs(i,ori);
    }
}
int main(){
    n=read();q=read();
    for(long long i = 1;i<=n;i++){
        for(long long j = i;j<=n;j++){
            g[j][i]=1;
        }
    }
    for(long long i = 1,x,y;i<=q;i++){
        x=read(),y=read();
        swap(g[x][y],g[y][x]);
        for(long long i = 1;i<=n;i++){
            dfs(i,i);
            memset(vis,0,sizeof vis);
        }
        long long ans=0;
        for(long long i = 1;i<=n;i++){
            for(long long j = i+1;j<=n;j++){
                if(tmp[i][j]+tmp[j][i]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        memset(tmp,0,sizeof tmp);
    }
    return 0;
}