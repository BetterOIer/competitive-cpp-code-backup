#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> city[155];
int f[155],low[155],dfn[155],k=1,k1=0;
struct node{
    int l,r;
}road[5005];
bool cmp(node a,node b){
    if(a.l==b.l)return a.r<b.r;
    return a.l<b.l;
}
void dfs(int x){
    dfn[x]=low[x]=k++;
    for(int i = 0;i<city[x].size();i++){
        int y = city[x][i];
        if(dfn[y]&&y!=f[x]){
            low[x]=min(low[x],dfn[y]);
        }
        if(!dfn[y]) {
            f[y]=x;
            dfs(y);
            low[x]=min(low[x],low[y]);
            if(low[y]>dfn[x]){
                road[++k1].l=min(y,x);
                road[k1].r=max(y,x);
            }
        }
    }

}
int main(){
    int n,m,c1,c2;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>c1>>c2;
        city[c1].push_back(c2);
        city[c2].push_back(c1);
    }
    for(int i=1; i<=n; i++) {
        if(!dfn[i]) dfs(i);
    }
    sort(road+1,road+k1+1,cmp);
    for(int i = 1;i<=k1;i++){
        cout<<road[i].l<<" "<<road[i].r<<endl;
    }
}