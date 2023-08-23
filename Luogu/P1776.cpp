#include<iostream>
using namespace std;
struct node{
    int val;
    int wei;
}goods[2000005];
int dp[400004];
int main(){
    int n,W,a,b,c,cn=0;
    cin>>n>>W;
    for(int i = 1;i<=n;i++){
        cin>>a>>b>>c;
        for(int j=1;j<=c;j<<=1)
        {
            goods[++cn].val=j*a,goods[cn].wei=j*b;
            c-=j;
        }
        if(c) goods[++cn].val=a*c,goods[cn].wei=b*c;
    }
    for(int i = 1;i<=cn;i++){
        for(int j = W;j>=goods[i].wei;j--){
            dp[j]=max(dp[j],dp[j-goods[i].wei]+goods[i].val);
        }
    }
    cout<<dp[W];
}