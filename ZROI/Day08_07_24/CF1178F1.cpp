/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
const long long mod = 998244353;
long long n,m;
long long a[1000005]={2147483647},dp[501][501];
int main(){
    n=read(),m=read();
    for(long long i = 1;i<=m;i++) a[i]=read();
    for(long long i=1;i<=n+1;i++) dp[i][i]=dp[i][i-1]=1;
    for(long long k = 1;k<n;k++){
		for(long long l=1;l+k<=n;l++){
            long long p=0,ans1=0,ans2=0,r=l+k;
			for(long long tmp=l;tmp<=r;tmp++) if(a[tmp]<a[p]) p=tmp;
			for(long long j=l;j<=p;j++) ans1=(ans1+dp[l][j-1]*dp[j][p-1])%mod;
			for(long long j=p;j<=r;j++) ans2=(ans2+dp[p+1][j]*dp[j+1][r])%mod;
			dp[l][r]=(ans1*ans2)%mod;
		}
    }
    cout<<dp[1][n];
    return 0;
}