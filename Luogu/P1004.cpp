#include<iostream>
using namespace std;
int a,b,c,size,ANS=0,dt[11][11],dx[2]={0,1},dy[2]={1,0},dp[11];
int rdp(){
    for(int i = 1;i<=size;i++) dp[i]=0;
    for(int i = 1;i<=size;i++){
        for(int w = 1;w<=size;w++){
            dp[w]=max(dp[w-1]+dt[i][w],dp[w]+dt[i][w]);
        }
    }
    return dp[size];
}
void dfs(int y,int x,int ans){
    if(y==size&&x==size){
        ANS=max(ans+rdp(),ANS);
        return ;
    }
    int k = dt[y][x];
    ans+=k;
    dt[y][x]=0;
    for(int i = 0;i<=1;i++){
        if(y+dy[i]<=size&&x+dx[i]<=size){
            dfs(y+dy[i],x+dx[i],ans);
        }
    }
    ans-=k;
    dt[y][x]=k;
}
int main(){
    cin>>size>>a>>b>>c;
    while(a!=0|b!=0||c!=0){
        dt[a][b]=c;
        cin>>a>>b>>c;
    }
    dfs(1,1,0);
    cout<<ANS;
}