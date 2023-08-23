/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
/*
考虑到70以内质数只有19个
判断取用奇偶个数即可
*/
#include<iostream>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
const long long PRIME[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
struct node{
    long long val;
    long long tim[19];
    long long wei;
}a[71];
long long dp[2][1<<19]={1};
bool flag=false;
long long wy[100005]={1};
int main(){
    n=read();
    for(long long i = 1;i<=n;i++) a[read()].val++,wy[i]=(wy[i-1]<<1)%mod;
    for(long long i = 2;i<=70;i++){
        long long tmp=i,cnt=0;
        while(tmp!=1){
            while(tmp%PRIME[cnt]==0){
                tmp/=PRIME[cnt];
                a[i].tim[cnt]++;
                a[i].wei^=(1<<cnt);
            }
            cnt++;
        }
    }
    for(long long i = 1;i<=70;i++){
        if(!a[i].val)continue;//!恼了，这个i不能拿来作为第一维存放的标签 因为会跳过
        flag=1-flag;
        memset(dp[flag],0,sizeof dp[flag]);
        for(long long j = 0;j<(1<<19);j++){
            long long j_n=j^a[i].wei;
            //cout<<j<<" "<<j_n<<endl;
            (dp[flag][j_n]+=dp[1-flag][j]*(wy[a[i].val-1]%mod)%mod)%=mod;//!CaO!!!这个1<<(a[i].val-1)必须预处理，否则一定会爆
            (dp[flag][j]+=dp[1-flag][j]*(wy[a[i].val-1]%mod)%mod)%=mod;
            //if(dp[flag][j_n]||dp[flag][j])cout<<i<<' '<<j<<' '<<j_n<<' '<<dp[flag][j_n]<<" "<<dp[flag][j]<<endl;
        }
    }
    cout<<(dp[flag][0]-1+mod)%mod;
    return 0;
}
