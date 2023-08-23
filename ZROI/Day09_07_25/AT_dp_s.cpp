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
string s;
const long long mod = 1e9+7;
long long len;
long long d;
long long dp[10005][105][2];
long long dfs(long long ori,long long sum,long long whi,bool lim){
    if(whi>=len){
        if(sum)return 0;
        return 1;
    }
    if(~dp[whi][sum][lim])return dp[whi][sum][lim];
    long long up = lim? s[whi]-'0':9,ans=0;
    for(long long i = 0;i<=up;i++){
         (ans+=dfs(ori*10+i,(sum+i)%d,whi+1,lim&&i==up))%=mod;
    }
    return dp[whi][sum][lim]=ans;
}
int main(){
    cin>>s>>d;
    for(long long _=0;_<10005;_++){
        for(long long __=0;__<105;__++){
            for(long long ___=0;___<2;___++){
                dp[_][__][___]=-1;
            }
        }
    }
    len= s.length();
    cout<<((dfs(0,0,0,1)-1)+mod)%mod;
    return 0;
}