#include<iostream>
#define MAXN 1001
using namespace std;
int dt[MAXN][MAXN],MAXS=0,n,m;
char k;
int dfs(int y,int x){
    if(y+1<=n&&dt[y+1][x]!=-1){
        dt[y+1][x]=dfs(y+1,x);
        return dt[y+1][x]+1;
    }else return 1;
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>k;
            if(k=='R')dt[i][j]--;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(dt[i][j]==0){
                dt[i][j]=dfs(i,j);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int nj=j,h=dt[i][j],s=dt[i][j],nows=0;
            while(dt[i][nj]!=-1&&nj<=m){
                h=min(h,dt[i][nj]);
                nows=h*(nj-j+1);
                s=max(s,nows);
                nj++;
            }
            MAXS=max(MAXS,s);
        }
    }
    cout<<MAXS*3;
}