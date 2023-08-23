#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxN=80004;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,m,s;
struct node{
    long long to;
    long long ori;
    long double xs=0;
};

vector<node>ro[maxN];
long long dfn[maxN],low[maxN],scc[maxN],tot,cnt;
bool instk[maxN];
deque<long long>stk;

struct NODE{
    long long to;
    long long val;
};
vector<NODE>ro2[maxN];
bool vis[maxN];
long long val[maxN];

void Tarjan(long long pos){
    //入
    dfn[pos]=low[pos]=++tot;
    stk.push_front(pos);
    instk[pos]=true;
    //回
    for(node to:ro[pos]){
        if(!dfn[to.to]){
            Tarjan(to.to);
            low[pos]=min(low[pos],low[to.to]);
        }else if(instk[to.to]){
            low[pos]=min(low[pos],dfn[to.to]);
        }
    }
    //离
    if(dfn[pos]==low[pos]){
        long long y;++cnt;
        do{
            y=stk.front();stk.pop_front();
            instk[y]=false;
            scc[y]=cnt;
        }while(y!=pos);
    }
}
long long dfs(long long pos){
    long long maxn=0;
    for(NODE to:ro2[pos]){
        if(vis[to.to])continue;
        maxn=max(maxn,dfs(to.to)+to.val);
    }
    return maxn+val[pos];
}
int main(){
    //freopen("P2656_7.in","r",stdin);
    n=read(),m=read();
    long double xs;
    for(long long i = 1,x,y,ori;i<=m;i++){
        x=read(),y=read(),ori=read();cin>>xs;
        ro[x].push_back((node){y,ori,xs});
    }
    s=read();
    Tarjan(s);
    for(long long i = 1;i<=n;i++){
        for(node to:ro[i]){
            if(scc[to.to]!=scc[i]){
                ro2[scc[i]].push_back((NODE){scc[to.to],to.ori});
                continue;
            }
            while(to.ori){
                val[scc[i]]+=to.ori;
                to.ori=floor(to.ori*to.xs);
            }
        }
    }
    cout<<dfs(scc[s]);
    return 0;
}