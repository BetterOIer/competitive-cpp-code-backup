#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    long long to;
    long long val;
};
struct Qnode{
    long long w;
    long long po;
    inline bool operator <(const Qnode &x)const{
        return w>x.w;
    }
};
priority_queue<Qnode>q;
vector <node> road[100004];
long long vis[100004],pre[100004];
long long dis[100004];
long long h,x,y,z;
int main(){
    h=read(),x=read(),y=read(),z=read();
    if(x==1 || y==1 || z==1){cout<<h;return 0;}
    for(long long i = 0;i<=x;i++) dis[i]=9223372036854775807ll;
    dis[1]=1;
    for(long long i = 0;i<x;i++){
        road[i].push_back((node){(i+y)%x,y});
        road[i].push_back((node){(i+z)%x,z});
    }
    q.push((Qnode){1,1});
    while(!q.empty()){
        Qnode now =q.top();q.pop();
        long long u=now.po;
        if(vis[u])continue;
        vis[u]=1;
        if(road[u].size()){
            for(node i:road[u]){
                if(dis[i.to]>dis[u]+i.val){
                    dis[i.to]=dis[u]+i.val;
                    pre[i.to]=u;
                    q.push((Qnode){dis[i.to],i.to});
                }
            }
        }
    }
    long long ans=0;
    for(long long i=0;i<x;i++){
        if(dis[i]<=h)ans+=((h-dis[i])/x+1);
    }
    cout<<ans;
    return 0;
}