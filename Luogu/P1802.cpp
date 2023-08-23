#include<iostream>
using namespace std;
long long dp[1000009],val[1001],ex1[1001],ex2[1001];
int main(){
    int n,en;
    cin>>n>>en;
    for(int i = 1;i<=n;i++){
        cin>>ex1[i]>>ex2[i]>>val[i];
    }
    for(int i = 1;i<=n;i++){
        for(int w = en;w>=0;w--){
            if(w>=val[i]) dp[w]=max(dp[w-val[i]]+ex2[i],dp[w]+ex1[i]);
            else dp[w]+=ex1[i];
        }
    }
    cout<<5*dp[en];
    return 0;
}