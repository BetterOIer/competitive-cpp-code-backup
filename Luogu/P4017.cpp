#include<iostream>
using namespace std;
unsigned long long dp[5005];
bool relation[5001][5001];
unsigned long long ans=0;
int main(){
    for(int i = 1;i<=5005;i++) dp[i]=1;
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int x1,x2;
        cin>>x1>>x2;
        relation[x1][x2]=true;
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<i;j++){
            if(relation[j][i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}