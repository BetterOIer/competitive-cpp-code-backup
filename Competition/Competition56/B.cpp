/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 实变函数学十遍，泛函学完心泛寒。 --数学系名言
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,k,a,b;
struct node{
    int val;
    int con;
    int chose;
}dp[100005];
int main(){
    int T=read();
    while(T--){
        n=read(),k=read(),a=read(),b=read();
        dp[1].con=1,dp[1].val=0,dp[1].chose=0;
        for(int i = 2;i<=n;i++){
            int cost=2147483647,last,chose=0;
            if(chose==dp[i-1].chose){
                cost=min(dp[i-1].val+a,cost);
                last=1;
            }
            if(dp[i-1].val+b*(dp[i-1].con+1>=k)<cost){
                cost=dp[i-1].val+b*(dp[i-1].con+1>=k);
                last=dp[i-1].con+1;
                chose=1;
            }
            dp[i].chose=chose;
            dp[i].val=cost;
            dp[i].con=last;
        }
        cout<<dp[n].val<<endl;
        memset(dp,0,sizeof dp);
    }
}