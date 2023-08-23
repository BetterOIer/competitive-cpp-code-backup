#include<iostream>
#include<vector>
using namespace std;
struct node{
    int to;
    int val;
};
vector <node> a[500005];
bool vis[500005];
void dfs(int ans,int po,int v,int to){
    if(po==to){
        if(ans==-1) cout<<0<<endl;
        else cout<<ans<<endl;
        return;
    }
    for(int i = 0;i<=a[po].size()-1;i++){
        if(!vis[a[po][i].to]){
            vis[a[po][i].to]=true;
            if(a[po][i].val<=v){
                if(ans==-1){
                    ans=a[po][i].val;
                    dfs(ans,a[po][i].to,v,to);
                    ans=-1;
                }else {
                    int o=ans;
                    ans=ans^a[po][i].val;
                    dfs(ans,a[po][i].to,v,to);
                    ans=o;
                }
            }else{
                dfs(ans,a[po][i].to,v,to);
            }
            vis[a[po][i].to]=false;
        }
    }
}
int main(){
    int n,u,v,w,q;
    cin>>n;
    for(int i = 1;i<=n-1;i++){
        cin>>u>>v>>w;
        a[u].push_back((node){v,w});
        a[v].push_back((node){u,w});
    }
    cin>>q;
    for(int i = 1;i<=q;i++){
        cin>>u>>v>>w;
        vis[u]=true;
        dfs(-1,u,w,v);
        vis[u]=false;
    }
}