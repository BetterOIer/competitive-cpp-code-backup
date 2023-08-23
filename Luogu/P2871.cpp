#include<iostream>
using namespace std;
long long val[100000],dp[1000000],importance[100000];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++) cin>>val[i]>>importance[i];
    for(int i = 1;i<=m;i++){
        for(int w = n;w>=val[i];w--){
            dp[w]=max(dp[w],dp[w-val[i]]+val[i]*importance[i]);
        }
    }
    cout<<dp[n];
    return 0;
}