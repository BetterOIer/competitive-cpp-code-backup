#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,k;
struct node{
    int to;
    int val;
};
vector<node>ro[2000005];
int dist[2000005];
bool vis[2000005];
struct Qnode{
    int now;
    int val;
    bool operator < (const Qnode &w)const{
        return val>w.val;
    }
};
priority_queue <Qnode> Q;
int main(){
    n=read(),m=read(),k=read();
    for(int i = 1,x,y,z;i<=m;i++){
        x=read(),y=read(),z=read();
        for(int j = 0;j<=k;j++){
            ro[x+j*n].push_back((node){y+j*n,z});
            ro[y+j*n].push_back((node){x+j*n,z});
            if(j<k)ro[x+j*n].push_back((node){y+n+j*n,z/2});
            if(j<k)ro[y+j*n].push_back((node){x+n+j*n,z/2});
        }
    }
    //for(int i=1;i<=k;i++)ro[n+(i-1)*n].push_back((node){n*(i+1),0});
    for(int i=0;i<=2000000;i++) dist[i]=2147483647;
    dist[1]=0;
    Q.push((Qnode){1,0});
    while(Q.size()){
        Qnode now = Q.top();Q.pop();
        if(vis[now.now])continue;
        vis[now.now]=1;
        for(node to:ro[now.now]){
            if(dist[to.to]>dist[now.now]+to.val){
                dist[to.to]=dist[now.now]+to.val;
                Q.push((Qnode){to.to,dist[to.to]});
            }
        }
    }
    int ans=2147483647;
    for(int i = 0;i<=k;i++){
        ans=min(ans,dist[n+n*i]);
    }
    cout<<ans;
}