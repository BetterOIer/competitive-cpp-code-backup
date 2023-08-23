#include<iostream>
#include<cstring>
using namespace std;
string s;
int dp[52][52],n;
int main(){
    cin>>s;
    n=s.length();
    memset(dp,127,sizeof(dp));
    for(int i=0;i<n;++i) dp[i][i]=1;
    for(int w = 1;w<n;w++){
        for(int i=0,j=0+w;j<n;++i,++j){
            if(s[i]==s[j]) dp[i][j]=dp[i+1][j]>dp[i][j-1]? dp[i][j-1]:dp[i+1][j];
            else for(int k = i;k<j;k++) dp[i][j]=dp[i][j]>dp[i][k]+dp[k+1][j]? dp[i][k]+dp[k+1][j]:dp[i][j];
        }
    }
    cout<<dp[0][n-1];
}