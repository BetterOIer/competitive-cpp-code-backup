#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
struct node{
    int to;
    int cost;
};
struct bian{
    int from, to,val;
}bi[200005];
vector <node> point[5005];
queue <int> Q;
int ans=0;
int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>u>>v>>w;
        point[u].push_back((node){v,w});
        point[v].push_back((node){u,w});
        bi[i].from=u,bi[i].to=v,bi[i].val=w;
    }
    for(int i = 1;i<=n;i++){
        if(point[i].size()){
            for(int w = 1;i<=n;i++){
                Q.
            }
        }
    }
    /* for(int i = 1;i<=m;i++){
        if(find(gram[i].a1)!=find(gram[i].a2)){
            s[find(gram[i].a1)]=find(gram[i].a2);
            k++,ans+=gram[i].val;
        }
    } */
    /* if(k<n)cout<<"orz";
    else cout<<ans; */
}