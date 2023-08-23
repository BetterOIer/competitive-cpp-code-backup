// TODO rewrite
#include<iostream>
#include<vector>
using namespace std;
const int mod = 201314;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int N,M,S;
struct node{
    int to;
    int whi;
    int belong;
};
vector<int>ro[10005];
vector<node>query[10005];
bool vis[10005];
int depth[10005];
int fa[10005],ans[100005],belonging[100005];
long long ANS[10005];
int find(int pos){return (pos==fa[pos]? pos:fa[pos]=find(fa[pos]));}
void Tarjan(int pos,int dep){
    vis[pos]=true;
    depth[pos]=dep;
    for(auto i:ro[pos]){
        if(vis[i])continue;
        Tarjan(i,dep+1);
        fa[i]=pos;
    }
    for(auto i:query[pos]){
        if(vis[i.to]){
            ans[i.whi]=find(i.to);
            belonging[i.whi]=i.belong;
        }
    }
}
int main(){
    N=read(),M=read();
    for(int i = 1;i<=N;i++){
        fa[i]=i;
    }
    for(int i = 1,y;i<N;i++){
        y=read();
        ro[i].push_back(y);
        ro[y].push_back(i);
    }
    int count=0;
    for(int i = 1,x,y,z;i<=M;i++){
        x=read(),y=read(),z=read();
        for(int j = x;j<=y;j++){
            query[j].push_back((node){z,++count,i});
            query[z].push_back((node){j,count,i});
        }
    }
    Tarjan(0,1);
    for(int i = 1;i<=count;i++){
        ANS[belonging[i]]=(ANS[belonging[i]]+depth[ans[i]])%mod;
    }
    for(int i = 1;i<=M;i++){
        cout<<ANS[i]<<endl;
    }
    return 0;
}