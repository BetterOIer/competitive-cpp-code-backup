#include<iostream>
#include<cstdio>
using namespace std;
bool vis[10];
int a[10],k=0;
int n;
void dfs(int x,int po){
    if(po==n){
        for(int i = 1;i<=n;i++){
            printf("%5d",a[i]);
        }
        cout<<endl;
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            a[++k]=i;
            dfs(i,po+1);
            a[k--]=0;
            vis[i]=false;
        }
    }
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        vis[i]=true;
        a[++k]=i;
        dfs(i,1);
        a[k--]=0;
        vis[i]=false;
    }
}