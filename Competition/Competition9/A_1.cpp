#include<iostream>
#include<queue>
using namespace std;
int a[21][21],dp[21][21],n,m;
int main(){
    cin>>m>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+a[i][j];
        }
    }
    cout<<dp[n][m];
    return 0;
}