#include<iostream>
using namespace std;
int a[1005],dp[1001][1001][2];
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i = 1;i<=n;i++) dp[i][i][0]=1;
    for(int len=1;len<=n;len++){
		for(int i=1,j=i+len;j<=n;i++,j++){
            if(a[i]<a[i+1])dp[i][j][0]+=dp[i+1][j][0];
            if(a[i]<a[j])dp[i][j][0]+=dp[i+1][j][1];
            if(a[j]>a[i])dp[i][j][1]+=dp[i][j-1][0];
            if(a[j]>a[j-1])dp[i][j][1]+=dp[i][j-1][1];
            dp[i][j][0]%=19650827;
            dp[i][j][1]%=19650827;
        }
    }
    int ans=(dp[1][n][0]+dp[1][n][1])%19650827;
    printf("%d",ans);
}