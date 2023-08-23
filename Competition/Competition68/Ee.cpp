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
const int mod = 1e9+7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,l,r;
int a[5005];
int sum[5005];
int dp[5010][5010],SUM[5010][5010],L,ans;
//mt19937_64  rnd(chrono::steady_clock::now().time_since_epoch().count());
bool check(long long x){
    long long tot=1,sum=0;
    for(int i = 1;i<=n;i++){
        if(a[i]>x){
            return false;
        }
        sum+=a[i];
        if(sum>x){
            sum=a[i];
            tot++;
            if(tot>m){
                return false;
            }
        }
    }
    return true;
}
int main(){
    n=read(),m=read()+1;
    for(int i = 1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
    r=sum[n];
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    SUM[0][1]=SUM[1][1]=dp[1][0]=dp[1][1]=1;
    L=1;
    for(int i = 2;i<=n;i++){
        if(sum[i]<=l)dp[i][1]=1;
        SUM[1][i] = SUM[1][i-1]+dp[i][1];
        while(sum[i]-sum[L-1]>l){
            L++;
        }
        for(int j = 2;j<=m;j++){
            dp[i][j] = ((SUM[j-1][i-1]-(L>1? SUM[j-1][L-2]:0))%mod+mod)%mod;
            SUM[j][i] = (SUM[j][i-1]+dp[i][j])%mod;
        }
    }
    for(int i = 1;i<=m;i++) (ans+=dp[n][i])%=mod;
    cout<<l<<" "<<ans<<endl;
    return 0;
}