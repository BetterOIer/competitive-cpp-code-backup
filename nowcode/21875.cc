#include<iostream>
using namespace std;
int dp[21]={100000000},used[21],inst[21][21],n,m,minn=0;
int cost(int i){
    int tmp=0;
    for(int j = 1;j<=m;j++){
        if(inst[i][j]==1&&used[j]==0){
            tmp++;
        }
    }
    return tmp*tmp;
}
void check(int i){
    inst[i][0]=1;
    minn=dp[i];
    for(int j = 1;j<=m;j++){
        if(inst[i][j]==1&&used[j]==0) used[j]=1;
    }
}
void print(){
    for(int i = 1;i<=m;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}
int main(){
    char nc;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>nc;
            inst[i][j]=nc-'0';
        }
    }
    for(int i = 1;i<=n;i++){
        int now_use=1;
        for(int j = 1;j<=m;j++){
            if(!inst[j][0]){
                if(dp[j-1]<minn+cost(j)){
                    dp[j]=dp[j-1];
                }else{
                    dp[j]=minn+cost(j);
                    now_use=j;
                }
            }
            /* if(dp[j-1]<minn+cost(j)){
                dp[j]=dp[j-1];
            }else{
                dp[j]=minn+cost(j);
                now_use=j;
            } */
        }
        check(now_use);
    }
    cout<<minn;
}