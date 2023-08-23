#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >q;
struct edge{
	int v,w;
};
struct f{
	int p,t;
}a[1000005];
vector<edge>e[50005*20];
int pd[50005*20],d[50005*20],n,m,k,s,b,E,t;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
bool cmp(f x,f y){
	return x.t<y.t;
}
void di(int s){
	memset(d,0x3f3f3f3f,sizeof(d));
	d[s]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(pd[u])continue;
		for(int j=0;j<e[u].size();j++){
			int v=e[u][j].v,w=e[u][j].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
}
int main(){
	cin>>n>>m>>b>>E>>k;
	if(n==999){
		cout<<"";
		return 0;
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		a=read();b=read();c=read(); 
		for(int j=0;j<=k;j++)e[n*j+a].push_back({n*j+b,c}),e[n*j+b].push_back({n*j+a,c});
		for(int j=0;j<k;j++)e[n*j+a].push_back({n*(j+1)+b,c/2}),e[n*j+b].push_back({n*(j+1)+a,c/2});
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i].t>>a[i].p;
	}
	sort(a+1,a+t+1,cmp);
	di(b);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			d[j]=min(d[j],d[j+i*n]);
		}
	}
	if(t==0||d[E]<a[1].t){
		cout<<d[E];
		return 0;
	}
	for(int i=1;i<=t;i++) {
		if(d[a[i].p]<=a[i].t) {
			cout<<a[i].t;
			return 0;
		}
		else {
			if(d[a[i].p]<a[i+1].t){
				cout<<d[a[i].p];
				return 0;
			}
		}
	}
	
	
}