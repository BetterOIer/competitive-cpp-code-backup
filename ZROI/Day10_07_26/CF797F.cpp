/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,s[10002],sum[10002];
struct node{
    long long x;
    long long maxn;
}ifo[10002];
deque<long long>q;
bool operator < (node a,node b){
    return a.x<b.x;
}
long long dp[5005][5005];
int main(){
    n=read(),m=read();
    for(long long i = 0;i<=m;i++) for(long long j = 0;j<=n;j++) dp[i][j]=123456789987654321;
    dp[0][0]=0;
    for(long long i = 1;i<=n;i++) ifo[i].x=read();
    for(long long i = 1+n;i<=m+n;i++){     
        ifo[i].x=read();
        ifo[i].maxn=read();
    }
    sort(ifo+1,ifo+1+n);
    sort(ifo+1+n,ifo+1+n+m);
    for(long long i=1+n;i<=m+n;i++)s[i-n]=s[i-1-n]+ifo[i].maxn;
    if(s[m]<n)return puts("-1"),0;
    for(long long i = 1;i<=m;i++){
        q.clear();
        dp[i][0]=0;q.push_back(0LL);
        for(long long j = 1;j<=s[i]&&j<=n;j++){
            dp[i][j]=dp[i-1][j],sum[j]=sum[j-1]+abs(ifo[j].x-ifo[i+n].x);
            while((q.size()&&dp[i-1][q.front()]-sum[q.front()]>dp[i-1][j]-sum[j])||(j-q.front()>ifo[i+n].maxn))q.pop_front();
            q.push_back(j),dp[i][j]=min(dp[i][j],sum[j]+dp[i-1][q.front()]-sum[q.front()]);
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}