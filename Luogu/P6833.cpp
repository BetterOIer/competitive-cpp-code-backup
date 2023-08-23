#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n=read(),m=read(),a=read(),b=read(),c=read();
int dt[1001][1001];
bool vis[1001][1001];
int dx[3]={-1,0,1};
int dy[3]={0,1,0};
long long ANS=9223372036854775807;
void dfs(int ny,int nx,int to,long long ans){
    if(nx==to&&ny==n){
        ANS=min(ANS,ans);
        return;
    }
    if(ans>=ANS) return;
    for(int i = 0;i<=2;i++){
        if(ny+dy[i]>0&&ny+dy[i]<=m&&nx+dx[i]>0&&nx+dx[i]<=n&&(!vis[ny+dy[i]][nx+dx[i]])){
            ans+=dt[ny+dy[i]][nx+dx[i]];
            vis[ny+dy[i]][nx+dx[i]]=true;
            dfs(ny+dy[i],nx+dx[i],to,ans);
            vis[ny+dy[i]][nx+dx[i]]=false;
            ans-=dt[ny+dy[i]][nx+dx[i]];
        }
    }
}
int main(){
    for(int i = 1;i<=n;i++) for(int j = 1;j<=m;j++) dt[i][j]=read();
    vis[1][a]=true;
    dfs(1,a,b,0);
    long long A1=ANS;
    ANS=9223372036854775807;
    dfs(1,a,c,0);
    A1+=ANS;
    cout<<A1;
}