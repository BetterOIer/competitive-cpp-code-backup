/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 昔日我曾苍老，如今风华正茂 --鲍勃·迪伦
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
const int mod = 10000;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dp[1005][1005];
int n,k;
int main(){
    n=read(),k=read(),dp[1][0] = 1;
    for(int i = 2;i<=n;i++){
        int sum=0;
        for(int j = 0;j<=k;j++){
            sum=(sum+dp[i-1][j])%mod;
            dp[i][j]=sum;
            if(j>=i-1)sum=((sum-dp[i-1][j-i+1])%mod+mod)%mod;
        }
    }
    cout<<dp[n][k];
}