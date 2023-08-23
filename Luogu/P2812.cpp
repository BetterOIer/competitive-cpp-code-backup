#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 10005;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int cnt=0,n,to,tot,dfn[maxn],low[maxn],scc[maxn],in[maxn],ou[maxn],inn,ouu;
vector<int>ro[maxn];
deque<int>stk;
bool instk[maxn];
void Tarjan(int pos){
    dfn[pos]=low[pos]=++tot;
    instk[pos]=true;
    stk.push_front(pos);
    for(int i:ro[pos]){
        if(!dfn[i]) {Tarjan(i); low[pos]=min(low[pos],low[i]);}
        else if(instk[i]) low[pos]=min(dfn[i],low[pos]);
    }
    if(dfn[pos]==low[pos]){
        int y;cnt++;
        do{
            y=stk.front();stk.pop_front();
            instk[y]=false;
            scc[y]=cnt;
        }while(pos!=y);
    }
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        to=read();
        while(to) {ro[i].push_back(to);to=read();}
    }
    for(int i = 1;i<=n;i++){
        if(dfn[i])continue;
        Tarjan(i);
    }
    for(int i = 1;i<=n;i++){
        for(int to:ro[i]){
            if(scc[i]!=scc[to]){
                ++in[scc[to]];
                ++ou[scc[i]];
            }
        }
    }
    for(int i = 1;i<=cnt;i++){
        if(!in[i])inn++;
        if(!ou[i])ouu++;
    }
    cout<<inn<<endl;
    cout<<max(inn,ouu)<<endl;
}