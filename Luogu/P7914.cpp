//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#define int long long
#define mod 1000000007
#define For(i,a,b) for(int i = a;i<=b;i++)
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,k,dp[510][510][6];
char s[510];
signed main(){
    n=read(),k=read();
    scanf("%s",s+1);
    For(i,1,n) dp[i][i-1][0]=1;
    For(len,1,n){
        For(l,1,n-len+1){
            int r=l+len-1;
            if(len<=k) dp[l][r][0]=dp[l][r-1][0]&&(s[r]=='*'||s[r]=='?');
            if(len>=2){
                if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?')) dp[l][r][1]=(dp[l+1][r-1][0]+dp[l+1][r-1][2]+dp[l+1][r-1][3]+dp[l+1][r-1][4])%mod;
                For(i,l,r-1){
                    dp[l][r][2]=(dp[l][r][2]+dp[l][i][3]*dp[i+1][r][0])%mod;
                    dp[l][r][3]=(dp[l][r][3]+(dp[l][i][2]+dp[l][i][3])*dp[i+1][r][1])%mod;
                    dp[l][r][4]=(dp[l][r][4]+(dp[l][i][4]+dp[l][i][5])*dp[i+1][r][1])%mod;
                    dp[l][r][5]=(dp[l][r][5]+dp[l][i][4]*dp[i+1][r][0])%mod;
                }
            }
            dp[l][r][5]=(dp[l][r][5]+dp[l][r][0])%mod;
            dp[l][r][3]=(dp[l][r][3]+dp[l][r][1])%mod;
        }
    }
    printf("%lld\n",dp[1][n][3]);
}