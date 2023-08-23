#include<iostream>
using namespace std;
long long dp[1000010];
struct supur{
    int t,c,flag;
}a[1000001];
int main(){
    int n,t;
    cin>>n>>t;
    for(int i = 1;i<=n;i++){
        cin>>a[i].t>>a[i].c>>a[i].flag;
        if(a[i].t==0&&a[i].c){cout<<"+&"<<endl;return 0;}
    }
    for(int i = 1;i<=n;i++){
        if(a[i].flag==0){
            for(int w = a[i].t;w<=t;w++){
                dp[w]=dp[w]>dp[w-a[i].t]+a[i].c? dp[w]:dp[w-a[i].t]+a[i].c;
            }
        }else{
            for(int w = t;w>=a[i].t;w--){
               dp[w]=dp[w]>dp[w-a[i].t]+a[i].c? dp[w]:dp[w-a[i].t]+a[i].c;
            }
        }
    }
    cout<<dp[t];
    return 0;
}