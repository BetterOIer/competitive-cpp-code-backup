/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
inline int qpow(int a,int b){int res=1;while(b){if(b&1)res=1ll*res*a;a=1ll*a*a;b>>=1;}return res;}
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int k,l,r,len;
int table[10]={0,1,4,9,16,25,36,49,64,81};
int dp[20][2000][2];
int dps(int ask,int pos,int pre,int ori,int lim){
    if(dp[pos][pre][lim]) return dp[pos][pre][lim];
    if(pos>len){
        if(pre*k==ori){cout<<k<<' '<<ori<<endl; return dp[pos][pre][lim]=1;}
        return dp[pos][pre][lim]=0;
    }
    int lar = lim? (ask/qpow(10,len-pos))%10:9;
    for(int i = 0;i<=lar;i++){
        dp[pos][pre][lim]+=dps(ask,pos+1,pre+table[i],ori*10+i,lim&&i==lar);
    }
    return dp[pos][pre][lim];
}
void init(){
    memset(dp,0,sizeof dp);
}
int main(){
    int t=read();
    while(t--){
        k=read(),l=read(),r=read();
        len=to_string(l-1).length();init();
        int ask1=dps(l-1,1,0,0,1);
        len=to_string(r).length();init();
        int ask2=dps(r,1,0,0,1);
        cout<<ask2-ask1;
    }
    return 0;
}