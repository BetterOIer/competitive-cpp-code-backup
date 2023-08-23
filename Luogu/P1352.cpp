#include<iostream>
#include<vector>
using namespace std;
struct node{
    int hap;
    int up;
    vector <int> down;
}staff[6003];
int dp[6003][2];
void dfs(int root){
    if(staff[root].down.size()){
        for(int i = 0;i<=staff[root].down.size()-1;i++){
            dfs(staff[root].down[i]);
            dp[root][0]+=max(dp[staff[root].down[i]][0],dp[staff[root].down[i]][1]);
            dp[root][1]+=dp[staff[root].down[i]][0];
        }
    }
    dp[root][1]+=staff[root].hap;
}
int main(){
    int n,U,D,root;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>staff[i].hap;
    for(int i = 1;i<=n-1;i++){
        cin>>U>>D;
        staff[U].up=D;
        staff[D].down.push_back(U);
    }
    for(int i = 1;i<=n;i++){
        if(staff[i].up==0){
            root=i;
            break;
        }
    }
    dfs(root);
    long long ans=max(dp[root][0],dp[root][1]);
    cout<<ans;
}