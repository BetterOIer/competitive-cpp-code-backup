/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
const long long mod = 1e9 + 7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k;
vector<int>ro[100005];
int dp[100005][107][2][2],tmp[107][2][2];
int size[100005];
inline int add(int x, long long y) {
    if (y >= mod) y %= mod;
    for (x += y; x >= mod; x -= mod);
    return x;
}
/* void dfs(int pos,int fa){
    size[pos]=dp[pos][0][0][0]=dp[pos][1][1][0]=1;
    for(int to:ro[pos]){
        if(to==fa)continue;
        dfs(to,pos);
        for(int i = 0;i<=min(size[pos],k);i++){
            tmp[i][0][0]=dp[pos][i][0][0];dp[pos][i][0][0]=0;
            tmp[i][0][1]=dp[pos][i][0][1];dp[pos][i][0][1]=0;
            tmp[i][1][0]=dp[pos][i][1][0];dp[pos][i][1][0]=0;
            tmp[i][1][1]=dp[pos][i][1][1];dp[pos][i][1][1]=0;
        }
        for(int i = 0;i<=min(size[pos],k);i++){
            for(int j = 0;j<=min(size[to],k-i);j++){
                dp[pos][i+j][0][0] = add(dp[pos][i+j][0][0],1ll*tmp[i][0][0]*dp[to][j][0][1]);
                dp[pos][i+j][0][1] = add(dp[pos][i+j][0][1],1ll*tmp[i][0][1]*(dp[to][j][0][1] + dp[to][j][1][1]));
                dp[pos][i+j][0][1] = add(dp[pos][i+j][0][1],1ll*tmp[i][0][0]*dp[to][j][1][1]);
                dp[pos][i+j][1][0] = add(dp[pos][i+j][1][0],1ll*tmp[i][1][0]*(dp[to][j][0][0] + dp[to][j][0][1]));
                dp[pos][i+j][1][1] = add(dp[pos][i+j][1][1],1ll*tmp[i][1][0]*(dp[to][j][1][0] + dp[to][j][1][1]));
                dp[pos][i+j][1][1] = add(dp[pos][i+j][1][1],1ll*tmp[i][1][1]*(1ll * dp[to][j][0][0] + dp[to][j][0][1] + 1ll * dp[to][j][1][0] + dp[to][j][1][1]));
            }
            size[pos]+=size[to];
        }
    }
} */
void dfs(int x, int fa) {
    size[x] = dp[x][0][0][0] = dp[x][1][1][0] = 1;
    for (unsigned e = 0; e < ro[x].size(); ++e) {
        int v = ro[x][e];
        if (v != fa) {
            dfs(v, x);
            for(int i = 0;i<=min(size[x],k);i++) {
                tmp[i][0][0] = dp[x][i][0][0]; dp[x][i][0][0] = 0;
                tmp[i][0][1] = dp[x][i][0][1]; dp[x][i][0][1] = 0;
                tmp[i][1][0] = dp[x][i][1][0]; dp[x][i][1][0] = 0;
                tmp[i][1][1] = dp[x][i][1][1]; dp[x][i][1][1] = 0;
            }
            for(int i = 0;i<=min(size[x],k);i++)
                for(int j = 0;j<=min(size[v],k-i);j++){
                    dp[x][i + j][0][0] = add(dp[x][i + j][0][0], 1ll * tmp[i][0][0] * dp[v][j][0][1]);
                    dp[x][i + j][0][1] = add(dp[x][i + j][0][1], 1ll * tmp[i][0][1] * (dp[v][j][0][1] + dp[v][j][1][1]));
                    dp[x][i + j][0][1] = add(dp[x][i + j][0][1], 1ll * tmp[i][0][0] * dp[v][j][1][1]);
                    dp[x][i + j][1][0] = add(dp[x][i + j][1][0], 1ll * tmp[i][1][0] * (dp[v][j][0][0] + dp[v][j][0][1]));
                    dp[x][i + j][1][1] = add(dp[x][i + j][1][1], 1ll * tmp[i][1][0] * (dp[v][j][1][0] + dp[v][j][1][1]));
                    dp[x][i + j][1][1] = add(dp[x][i + j][1][1], 1ll * tmp[i][1][1] * (1ll * dp[v][j][0][0] + dp[v][j][0][1] + 1ll * dp[v][j][1][0] + dp[v][j][1][1]));
                }
                size[x] += size[v];
        }
    }
}
int main(){
    n=read(),k=read();
    for(int i = 1,x,y;i<n;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
    }
    dfs(1,0);
    cout<<(int)((dp[1][k][0][1] + dp[1][k][1][1]) % mod);
    return 0;
}
