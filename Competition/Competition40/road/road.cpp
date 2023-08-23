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
struct node{
    int to;
    long long val;
};
struct Qnode{
    int po;
    long long step;
    long long val;
    bool operator < (const Qnode &w)const{
        return w.val<val;
    }
};
priority_queue<Qnode>Q;
vector<node> po[300005];
long long dist[300005];
bool vis[300005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),m=read();
    for(int i = 1;i<=n;i++) dist[i]=9223372036854775807ll;
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        po[u].push_back((node){v,w});
    }
    Qnode sta;
    sta.po=1;
    sta.step=0;
    sta.val=0;
    dist[1]=0;
    vis[1]=true;
    Q.push(sta);
    while(Q.size()){
        Qnode now = Q.top();Q.pop();
        if(now.po==n) break;
        vis[now.po]=true;
        for(node i:po[now.po]){
            if(vis[i.to])continue;
            long long ste=now.val;
            long long maxp=max(ste,(now.step+1)*i.val);
            if(dist[i.to]>maxp){
                dist[i.to]=maxp;
                Q.push((Qnode){i.to,now.step+1,maxp});
            }
        }
    }
    cout<<dist[n]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}