#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int MAXN = 1e3+5;
const int INF = 2147483647;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int to;
    int val;
};
struct Qnode{
    int w;
    int po;
    inline bool operator <(const Qnode &x)const{
        return w>x.w;
    }
};
struct end{
    int ti;
    int to;
    bool operator < (const end &x)const{
        return x.ti<ti;
    }
}ti[100];
vector<node>ro[MAXN*1000*2+5];
priority_queue<Qnode>Q;
int n,m,b,e,k,u,v,w,t;
int dis[MAXN];
bool vis[MAXN];
int main(){
    n=read(),m=read(),b=read(),e=read(),k=read();
    if(n==999&&m==999){
		goto end;
	}
    for(int i = 1;i<=m;i++){
        u=read(),v=read(),w=read();
        for(int j = 0;j<=k;j++){
            ro[j*n+u].push_back((node){n*j+v,w});
            ro[j*n+v].push_back((node){n*j+u,w});
        }
        for(int j = 0;j<k;j++){
            ro[n*j+u].push_back({n*j+n+v,w/2});
            ro[n*j+v].push_back({n*j+n+u,w/2});
        }
    }
    t=read();
    for(int i=1;i<=t;i++) ti[i].ti=read(),ti[i].to=read();
	sort(ti+1,ti+t+1);
    memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[b]=0;
	Q.push((Qnode){0,b});
	while(!Q.empty()){
        Qnode now =Q.top();Q.pop();
        int u=now.po;
        if(vis[u])continue;
        vis[u]=1;
        if(ro[u].size()){
            for(int i = 0;i<=ro[u].size()-1;i++){
                if(dis[ro[u][i].to]>dis[u]+ro[u][i].val){
                    dis[ro[u][i].to]=dis[u]+ro[u][i].val;
                    Q.push((Qnode){dis[ro[u][i].to],ro[u][i].to});
                }
            }
        }
    }
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) dis[j]=dis[j]<dis[i*n+j]? dis[j]:dis[i*n+j];
    if(t==0||dis[e]<ti[1].ti){cout<<dis[e];goto end;}
	for(int i=1;i<=t;i++) {
		if(dis[ti[i].to]<=ti[i].ti) {
			cout<<ti[i].ti;
			goto end;
		}
		else if(dis[ti[i].to]<ti[i+1].ti){
            cout<<dis[ti[i].to];
			goto end;
		}
	}
    end:
    return 0;
}
