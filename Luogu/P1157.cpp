#include<iostream>
using namespace std;
bool zg[1000000]={true};
int now[1000000],k=0,n,r;
void dfs(int x){
    if(x==r+1){
        for(int i = 1;i<=k;i++){
            printf("%3d",now[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = now[k];i<=n;i++){
        if(!zg[i]){
            now[++k]=i;
            zg[i]=true;
            dfs(x+1);
            zg[i]=false;
            now[k--]=0;
        }
    }
}
int main(){
    cin>>n>>r;
    dfs(1);
}