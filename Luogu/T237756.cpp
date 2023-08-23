#include<iostream>
using namespace std;
int num[1048578],search;
int dp[1048578][3];
long long ans=9223372036854775807ll;
void dfs(long long cnt,int l,int r){
    if(l==r){
        ans=min(ans,cnt);
        return ;
    }
    int mid1=(l+r)>>1,mid2=(l+r+1)>>1;
    if(num[mid1]>=search){
        dfs(cnt+1,l,mid1);
    }else{
        dfs(cnt+1,mid1+1,r);
    }
    if(num[mid2]-1>=search){
        dfs(cnt+1,l,mid2-1);
    }else{
        dfs(cnt+1,mid2,r);
    }
    
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>num[i];
    }
    int m;
    cin>>m;
    for(int i = 1;i<=m;i++){
        cin>>search;
        ans=9223372036854775807ll;
        dfs(0,1,n);
        cout<<ans<<endl;
    }
}