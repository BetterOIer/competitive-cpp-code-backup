#include<iostream>
using namespace std;
int a[110],dp1[120],dp2[120],ans=0;
int main(){
    int n;cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++){
        dp1[i]=1;
        for(int j = 1;j<i;j++){
            if(a[i]>a[j]) dp1[i]=max(dp1[j]+1,dp1[i]);
        }
    }
    for(int i = n;i>=1;i--){
        dp2[i]=1;
        for(int j = n;j>i;j--){
            if(a[i]>a[j]) dp2[i]=max(dp2[j]+1,dp2[i]);
        }
    }
    for(int i = 1;i<=n;i++) ans=max(dp1[i]+dp2[i],ans);
    cout<<n-ans+1;
    return 0;
}