//TODO
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dp[505][505];
int main(){
    int n=read();
    string s;
    cin>>s;
    for(int i = 0;i<n;i++){
        dp[i][i]=1;
    }
    for(int len = 2;len<=n;len++){
        for(int i= 0;i+len-1<n;i++){
            int j = i+len-1;dp[i][j]=2147483647;
            if(s[i]==s[j])dp[i][j]=dp[i][j-1];
            else{
                for(int k = i;k<=j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[0][n-1];
}