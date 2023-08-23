#include<iostream>
#include<vector>
using namespace std;
struct node{
    int to;
    int val;
};
struct tr{
    int bit[2];
}trietree[2000001];
int sum[2000001],tot=0;
vector <node> tree[100000];
void build(int now,int val){
    for(int i =(1<<30);i;i>>=1){
        bool flag=val&i;
        if(!trietree[now].bit[flag]){
            trietree[now].bit[flag]=++tot;
        }
        now=trietree[now].bit[flag];
    }
}
void dfs(int fa,int now){
    for(auto i:tree[now]){
        if(i.to!=fa){
            sum[i.to]=sum[now]^i.val;
            dfs(now,i.to);
        }
    }
}
long long query(int now,int val){
    long long ans=0;
    for(int i = (1<<30);i;i>>=1){
        bool flag=val&i;
        if(trietree[now].bit[!flag]){
            ans+=i;
            now=trietree[now].bit[!flag];
        }
        else now=trietree[now].bit[flag];
    }
    return ans;
}
int main(){
    int n,u,v,w;
    cin>>n;
    for(int i = 1;i<n;i++){
        cin>>u>>v>>w;
        tree[u].push_back((node){v,w});
        tree[v].push_back((node){u,w});
    }
    dfs(-1,1);
    for(int i=1;i<=n;++i)build(0,sum[i]);
    long long ANS=0;
    for(int i=1;i<=n;++i) ANS=max(ANS,query(0,sum[i]));
    printf("%lld\n",ANS);
}