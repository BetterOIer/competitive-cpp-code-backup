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
#include<queue>
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m;
long long a[302][302],b[302][302];
struct node{
    long long to;
    long long val;
};
long long dis[100005],cnt[100005];
bool vis[100005];
vector<node>ro[605];
bool spfa(long long s){
    queue<long long>Q;
    memset(dis,0x3f3f3f3f,sizeof dis);
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    dis[s]=0,vis[s]=true;Q.push(s);
    while(Q.size()){
        long long now = Q.front();Q.pop();
        vis[now]=false;
        for(node to:ro[now]){
            if(dis[to.to]>dis[now]+to.val){
                dis[to.to]=dis[now]+to.val;
                cnt[to.to]=cnt[now]+1;
                if(cnt[to.to]>=n+m+1)return false;
                if(!vis[to.to])Q.push(to.to),vis[to.to]=true;
            }
        }
    }
    return true;
}
int main(){
    long long t=read();
    while(t--){
        n=read(),m=read();
        for(long long i = 1;i<n;i++){
            for(long long j = 1;j<m;j++){
                b[i][j]=read();
            }
        }
        memset(a,0,sizeof a);
        for(long long i = n;i>=1;i--){
            for(long long j = m;j>=1;j--){
                a[i][j]=b[i][j]-a[i+1][j]-a[i][j+1]-a[i+1][j+1];
            }
        }
       /*  cout<<endl;
        for(long long i = 1;i<=n;i++){
            for(long long j = 1;j<=m;j++){
                cout<<a[i][j]<<" \n"[j==m];
            }
        }
        cout<<"===\n"; */
        for(long long i = 0;i<=m+n;i++)ro[i].clear();
        for(long long i = 1,mx,mn;i<=n;i++){
            for(long long j = 1;j<=m;j++){
                mx=1000000-a[i][j],mn=-a[i][j];
                if(!((i+j)&1)) ro[j+n].push_back((node){i,mx}),ro[i].push_back((node){j+n,-mn});
                else ro[j+n].push_back((node){i,-mn}),ro[i].push_back((node){j+n,mx});
            }
        }
        for(long long i = 1;i<=n+m;i++)ro[0].push_back((node){i,0});
        bool NO_NG = spfa(0);
        if(!NO_NG){cout<<"NO\n";continue;}
        for(long long i = 1;i<=n;i++){
            for(long long j = 1;j<=m;j++){
                if((i+j)&1)a[i][j]=a[i][j]-dis[i]+dis[j+n];
                else a[i][j]=a[i][j]+dis[i]-dis[j+n];
            }
        }
        cout<<"YES\n";
        for(long long i = 1;i<=n;i++){
            for(long long j = 1;j<=m;j++){
                cout<<a[i][j]<<" \n"[j==m];
            }
        }
    }
    return 0;
}