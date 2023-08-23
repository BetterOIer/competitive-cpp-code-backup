#include<iostream>
using namespace std;
int weight[5010],dp[50000];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++) cin>>weight[i];
    for(int i = 1;i<=m;i++){
        for(int w= n;w>=weight[i];w--){
            dp[w]=max(dp[w],dp[w-weight[i]]+weight[i]);
        }
    }
    cout<<dp[n];
    return 0;
}