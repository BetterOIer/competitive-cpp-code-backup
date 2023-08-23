#include<iostream>
#include<queue>
using namespace std;
int a[21][21],dp[21][21];
struct node{
    int x;
    int y;
};
queue <node> Q;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    while(!Q.empty()){
        node now=Q.front();
        Q.pop();
        if(now.x+1<=m){
            
        }
    }
}