#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,tot,cnt;
int low[100006],dfn[100006],scc[100006],val[100006],MINV,GS=1;
bool instk[100006];
deque<int>stk;
vector<int>ro[100006];
void Tarjan(int pos){
    dfn[pos]=low[pos]=++tot;
    instk[pos]=true;
    stk.push_front(pos);
    for(int to:ro[pos]){
        if(!dfn[to]){
            Tarjan(to);
            low[pos]=min(low[pos],low[to]);
        }else if(instk[to]){
            low[pos]=min(low[pos],dfn[to]);
        }
    }
    if(dfn[pos]==low[pos]){
        int y,minv=2147483647,gs=0;cnt++;
        do{
            y=stk.front();stk.pop_front();
            instk[y]=false;
            scc[y]=++cnt;
            if(val[y]<minv){
                minv=val[y];
                gs=1;
            }else if(val[y]==minv){
                ++gs;
            }
        }while(y!=pos);
        GS*=gs;
        MINV+=minv;
    }
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        val[i]=read();
    }
    m=read();
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        ro[x].push_back(y);
    }
    for(int i = 1;i<=n;i++){
        if(dfn[i])continue;
        Tarjan(i);
    }
    cout<<MINV<<" "<<GS;
    return 0;
}