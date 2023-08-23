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
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,x_s,y_s;
struct node{
    long long to;
    long long val;
};
vector<node>tr[100005];
bool x[100005],y[100005];
long long dp[100005][3];
void dfs(long long pos,long long fa){
    if(!x[pos]&&!y[pos])dp[pos][0]=dp[pos][1]=dp[pos][2]=0;
    if(x[pos])dp[pos][1]=0;
    if(y[pos])dp[pos][2]=0;
    for(node to:tr[pos]){
        if(to.to==fa)continue;
        dfs(to.to,pos);
        if(!x[pos]&&!y[pos])dp[pos][0]+=min(dp[to.to][0],to.val+min(dp[to.to][1],dp[to.to][2]));
        if(!y[pos])dp[pos][1]+=min(min(dp[to.to][0],dp[to.to][1]),to.val+dp[to.to][2]);
        if(!x[pos])dp[pos][2]+=min(min(dp[to.to][0],dp[to.to][2]),to.val+dp[to.to][1]);
    }
}
int main(){
    memset(dp,0x3f3f3f3f,sizeof dp);
    n=read();
    x_s=read();
    for(long long i = 1,whi;i<=x_s;i++){
        whi=read();
        x[whi]=true;
    }
    y_s=read();
    for(long long i = 1,whi;i<=y_s;i++){
        whi=read();
        y[whi]=true;
    }
    for(long long i = 1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        tr[u].push_back((node){v,w});
        tr[v].push_back((node){u,w});
    }
    dfs(1,0);
    cout<<min(dp[1][0],min(dp[1][1],dp[1][2]));
    return 0;
}