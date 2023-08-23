/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,mx,a[1010],dp[1010][2],ans;
bool ap[1020];
int main(){
    n=read(),mx=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();ap[a[i]]?--n,--i:ap[a[i]]=1;//这去重太妙了。撅了
    }
    sort(a+1,a+n+1);dp[n][0]=a[n],dp[n][1]=-a[n];
    for(int i = n-1;i>=1;--i){
        if(a[i+1]-a[i]>mx)dp[i][0]=a[i],dp[i][1]=-a[i];
        else{
            int cnt = 1e9;
            for(int j = i+1;j<=n&&a[j]-a[i]<=mx;++j)cnt=min(dp[j][1],cnt);
            dp[i][0] = cnt+a[i];
            
            cnt =-1e9;
            for(int j = i+1;j<=n&&a[j]-a[i]<=mx;++j)cnt=max(dp[j][0],cnt);
            dp[i][1] = cnt-a[i];
        }
    }
    for(int i=1;i<=n&&a[i]<=mx;++i)ans=max(ans,dp[i][0]);
    printf("%d",ans);
    return 0;
}