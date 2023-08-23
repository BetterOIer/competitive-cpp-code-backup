#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long sum=0,ans[1000005];
int End,Ep, Ee;
bool vis[1000005];
struct node{
    int to;
    int len;
    int beau;
};
vector <node> ro[1000005];
vector <int> huan;
bool dfs(int x,int fa,int fp,int fe){
    if(vis[x]){
        End=x,Ep=fp,Ee=fe;
        return true;
    }
    vis[x]=1;
    for(auto i:ro[x]){
        if(i.to==fa) continue;
        if(dfs(i.to,x,i.beau,i.len)){
            if(x!=End)ans[x]-=(fp>i.beau? i.len:fe);
            else ans[x] -= i.beau > Ep ? Ee : i.len;
            huan.push_back(x);
            return x!=End;
        }
    }
    return false;
}
void dfs(int x){
    vis[x]=true;
    for(auto i:ro[x]){
        if(vis[i.to])continue;
        ans[i.to] = ans[x];
        dfs(i.to);
    }
}
int main(){
    int n=read();
    for(int i = 1,u,v,w,x;i<=n;i++){
        u=read(),v=read(),w=read(),x=read();
        ro[u].push_back((node){v,w,x});
        ro[v].push_back((node){u,w,x});
        sum+=w;
    }
    dfs(1,0,0,0);
    int size=sizeof vis;
    for(int i = 0;i<size;i++)vis[i]=false;
    for(auto i:huan){
        vis[i]=true;
        ans[i]+=sum;
    }
    for(auto i:huan) dfs(i);
    for(int i = 1;i<=n;i++) cout<<ans[i]<<"\n";
}