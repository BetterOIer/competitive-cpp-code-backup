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
vector<int> edge[10005];
int v[10005],n,k,dp[10005][105];
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
void dfs(int cur,int fa)
{
    int sum[105];
    memset(sum,0,sizeof(sum));
    for(int i:edge[cur]){
        if(i==fa) continue;
        dfs(i,cur);
        for(int j=0;j<=k+1;j++) sum[j]+=dp[i][j];
    }
    dp[cur][0]=sum[k]+v[cur];
    for(int i=1;i<=k+1;i++){
        if(i<=(k+1)/2){
            for(int j:edge[cur]){
                if(j==fa) continue;
                dp[cur][i]=max(dp[cur][i],sum[k+1-i-1]-dp[j][k+1-i-1]+dp[j][i-1]);
            }
        }
        else dp[cur][i]=sum[i-1];
        
    }
    for(int i=k;i>=0;i--) dp[cur][i]=max(dp[cur][i],dp[cur][i+1]);
    
}
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++) v[i]=read();
    for(int i=1,x,y;i<n;i++){
        x=read(),y=read();
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,-1);
    cout<<dp[1][0];
    return 0;
}