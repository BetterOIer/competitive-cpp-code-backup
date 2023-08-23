/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#define maxn 1001
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int dit[maxn][maxn],dfd[maxn][maxn],n,m;
double dis[maxn][maxn],dist[maxn];
bool be[maxn];
double prim(){
    for(int i = 0;i<maxn;i++) dist[i]=1109567.0;
    for(int i = 0;i<maxn;i++) be[i]=false;
    double res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!be[j] && (t==-1 || dist[t]>dist[j])) t=j;
        }
        be[t]=true;
        if(i && dist[t]==1109567.0) return 1109567.0;
        if(i) res+=dist[t];
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dis[t][j]);
        }
        
    }
    return res;

}
void solve(){
    double l=0,r=100005,mid;
    while(r-l>1e-6){
        mid=(l+r)*0.5;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
                dis[i][j]=dis[j][i]=1.0*dit[i][j]-mid*dfd[i][j];
            }
        }
        double ans=prim();
        if(ans>0)l=mid;
        else r=mid;
    }
    printf("%.3lf",l);
}
int main(){
    n=read(),m=read();
    m=((n*n-n)>>1);
    for(int i =1,x,y,Dfd,Dis;i<=m;i++){
        x=read(),y=read(),Dfd=read(),Dis=read();
        dit[x][y]=dit[y][x]=Dis;
        dfd[x][y]=dfd[y][x]=Dfd;
    }
    solve();
    return 0;
}