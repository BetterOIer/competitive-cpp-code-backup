#include<iostream>
using namespace std;
const int INF=-2147483647;
int a[500005];
int dp[2][500005][3];
int main(){
    int n=0,each;
    while(cin>>each){
        n++;a[n]=each;
    }
    for(int i = 0;i<=1;i++) for(int j = 0;j<=n;j++) dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=INF;
    dp[0][0][1]=0;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=i;j++){
            if(j+2<=i)dp[i&1][j][0]=max(dp[(i-1)&1][j+1][0],max(dp[(i-1)&1][j+1][1],dp[(i-1)&1][j+1][2]))+a[i];
            if(j)dp[i&1][j][1]=max(dp[(i-1)&1][j-1][0],max(dp[(i-1)&1][j-1][1],dp[(i-1)&1][j-1][2]))-a[i];
            if(j<i)dp[i&1][j][2]=max(dp[(i-1)&1][j][0],max(dp[(i-1)&1][j][1],dp[(i-1)&1][j][2]));
        }
    }
    cout<<max(dp[n&1][0][0],max(dp[n&1][0][1],dp[n&1][0][2]));
    return 0;
}