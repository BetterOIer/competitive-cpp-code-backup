#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int a[555][555],n,cnt=0;
int ds[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
void dfs(int x,int y,int d,int maxn){
    if(maxn==3) return ;
    if(y==2&&x==4){
        a[1][4]=++cnt;
        a[2][4]=++cnt;
        return;
    }
    if(y==maxn&&x==maxn){
        a[y][x]=++cnt;
        dfs(x+ds[d+1][0],y+ds[d+1][1],d+1,maxn);
    }else if(y==maxn&&x==1){
        a[y][x]=++cnt;
        if(y-1==3)return;
        a[y-1][x]=++cnt;
        dfs(x+1,y-1,2,maxn-1);
    }else if(y==1&&x==maxn){
        a[y][x]=++cnt;
        if(x-1==3)return;
        a[y][x-1]=++cnt;
        dfs(x-1,y+1,0,maxn-1);
    }else{
        a[y][x]=++cnt;
        dfs(x+ds[d][0],y+ds[d][1],d,maxn);
    }
}
int main(){
    n=read();
    if(n<=2){
        cout<<-1<<endl;
        return 0;
    }
    else if(n>3){if(n&1){
        a[1][n]=++cnt;
        dfs(n,2,0,n);
    }else{
        a[n][1]=++cnt;
        dfs(2,n,2,n);
    }}
    a[3][1]=cnt+4,
    a[3][2]=cnt+9,
    a[3][3]=cnt+3,
    a[2][1]=cnt+5,
    a[2][2]=cnt+1,
    a[2][3]=cnt+2,
    a[1][1]=cnt+8,
    a[1][2]=cnt+7,
    a[1][3]=cnt+6;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}