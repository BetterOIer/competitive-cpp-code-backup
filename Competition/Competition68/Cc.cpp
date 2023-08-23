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
long long m,p;
inline long long qpow(long long a,long long b){long long res=1;while(b){if(b&1)res=1ll*res*a%p;a=1ll*a*a%p;b>>=1;}return res;}
long long ok[7],cnt=0;
long long dp[1000][130][7];
long long dfs(long long pos,long long ori,long long bef){
    if(pos==m) return bef==127;
    if(dp[pos][bef][ori%7])return dp[pos][bef][ori%7];
    long long ans=0;
    // if(!ok[ori%7]){
        // cnt++;
        // bef+=1<<(ori%7);
    // }
    // ok[ori%7]+=1;;
    for(long long i = 0;i<=9;i++){
    	int y=(ori*10+i)%7;
        (ans+=dfs(pos+1,y,bef|(1<<y))%p)%=p;
    }
    // ok[ori%7]-=1;
    // if(!ok[ori%7]){ 
        // cnt--;
        // bef-=(1<<(ori%7));
    // }
    return dp[pos][bef][ori%7]=ans;
}
int main(){
    m=read(),p=read();
    cout<<dfs(0,0,0);
    return 0;
}