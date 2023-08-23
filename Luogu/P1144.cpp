#include<cstdio>
#include<cstdlib>
#include<queue>
#define maxn 1000000+1
#define maxm 2000000+1
#define INF 0x7f7f7f7f
#define MOD 100003
using namespace std;
vector<int>roads[maxn];
int dep[maxn];
bool vis[maxn];
int ans[maxn];
int main(){
    int N,M;scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++){
        int x,y;scanf("%d%d",&x,&y);
        roads[x].push_back(y);
        roads[y].push_back(x);
    }
    queue<int>Q;dep[1]=0;vis[1]=1;Q.push(1);ans[1]=1;
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        for(int i=0;i<roads[x].size();i++){
            int t=roads[x][i];
            if(!vis[t]){vis[t]=1;dep[t]=dep[x]+1;Q.push(t);}
            if(dep[t]==dep[x]+1){ans[t]=(ans[t]+ans[x])%MOD;}
        }
    }
    for(int i=1;i<=N;i++) printf("%d\n",ans[i]);
    
    return 0;
}