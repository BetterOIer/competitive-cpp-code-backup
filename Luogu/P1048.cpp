#include<iostream>
using namespace std;
int dp[1009];
int val[101],tim[101];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>tim[i]>>val[i];
    }
    for(int i = 1;i<=m;i++){
        for(int w = n;w>=tim[i];w--){
            dp[w]=max(dp[w-tim[i]]+val[i],dp[w]);
        }
    }
    cout<<dp[n];
    return 0;
}