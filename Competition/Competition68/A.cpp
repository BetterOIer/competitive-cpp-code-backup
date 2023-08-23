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
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,maxn;
int a[1005];
int dp[1005][1005];
int maxc[1005],last[1005],cf[1005];
map<int,int>m;
int main(){
    n=read(),maxn=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i = n;i>=1;i--){
        m[a[i]]=i;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            auto _ = lower_bound(a+1,a+n+1,a[j]-maxn);
            for(int k = m[*_];k<=j;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][k]+a[j]);
            }
            if(dp[i][j]>=maxc[i]&&j>last[i-1]){
                maxc[i]=dp[i][j];
                last[i]=j;
            }
        }
    }
    for(int i = 1;i<=n&&maxc[i]>=0;i++){
        cf[i]=maxc[i]-maxc[i-1];
    }
    int ans=0,p=0;
    for(int i = 1;i<=n&&cf[i]>=0;i++){
        if(cf[i]>=ans){
            ans=cf[i];
            p=i;
        }
    }
    cout<<((p&1? 1:-1)*ans)<<endl;
    return 0;
}