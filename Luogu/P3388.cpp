#include<bits/stdc++.h>
using namespace std;
struct edge{
    int nextt,mark;
}pre[200010];
int n,m,idx,cnt,tot;
int head[100010],dfn[100010],LOW[100010];
bool cut[100010];
void add (int x,int y){
    pre[++cnt].nextt=y;
    pre[cnt].mark=head[x];
    head[x]=cnt;
}
void tarjan(int u,int fa){
    dfn[u]=LOW[u]=++idx;
    int child=0;
    for(int i = head[u];i!=0;i=pre[i].mark){
        int next=pre[i].nextt;
        if (!dfn[next]){
            tarjan (next,fa);
            LOW[u]=min (LOW[u],LOW[next]);
            if (LOW[next]>=dfn[u]&&u!=fa)
                cut[u]=1;
            if(u==fa)
                child++;
        }
        LOW[u]=min(LOW[u],dfn[next]);
    }
    if(child>=2&&u==fa) cut[u]=1;
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add (a,b);
        add (b,a);
    }
    for(int i=1;i<=n;i++) if (dfn[i]==0)tarjan (i,i);
    for(int i=1;i<=n;i++) if (cut[i]) tot++;
    printf ("%d\n",tot);
    for(int i=1;i<=n;i++) if (cut[i]) printf ("%d ",i);
}