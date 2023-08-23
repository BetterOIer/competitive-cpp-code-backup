#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n;
ll ans,a[150004],f[2][150004],dep[150004];
vector<int>F[150004];
void dfs(int x,int fa,int &D1,int &D2){
    dep[x]=dep[fa]+1;
    int D1=0,d2=0;
    for(int y:F[x]){
        if(y==fa)continue;
        int dd1,dd2;
        dfs(y,x,dd1,dd2);
        if(f[0][x]<=f[0][y]){
            if(f[0][x])
        }
        f[1][x]=max(f[1][x],f[1][y]);
    }
    if(!f[0][x]){

    }
    f[0][x]=f[0][x]*2+a[x];
    f[1][x]=f[1]
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        F[u].push_back(v);
        F[v].push_back(u);
    }
    dfs(1,0,0,0);

}