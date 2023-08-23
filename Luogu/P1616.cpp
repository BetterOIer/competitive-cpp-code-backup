#include<iostream>
using namespace std;
long long dp[10000005];
long long  val[10005],tim[10005];
int main(){
    int t,m;
    cin>>t>>m;
    for(int i = 1;i<=m;i++){
        cin>>tim[i]>>val[i];
    }
    for(int i = 1;i<=m;i++){
        for(int w = tim[i];w<=t;w++){
            dp[w]=max(dp[w-tim[i]]+val[i],dp[w]);
        }
    }
    cout<<dp[t];
    return 0;
}