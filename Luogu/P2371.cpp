#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<long long,long long>node;
const long long maxn=3000005;
struct tree{
	long long to,next,val;
}tr[maxn<<1];
long long head[maxn],cnt,ans1,ans2;
long long n,l,r,a[15];
long long dis[maxn],vis[maxn];
long long flag=0x3f3f3f3f;
priority_queue<node,vector<node>,greater<node> >q;
void add(long long u,long long v,long long w){
	tr[++cnt].next=head[u];
	head[u]=cnt;
	tr[cnt].to=v;
	tr[cnt].val=w;
}
int main(){
	cin>>n>>l>>r;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)flag=min(flag,a[i]);
	}
	if(flag==1){
		cout<<r-l+1<<endl;
		return 0;
	}
	for(long long i=0;i<flag;i++){
		for(long long j=1;j<=n;j++){
			if(a[j]!=flag)add(i,(i+a[j])%flag,a[j]);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q.push({0,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		long long x=t.second;
		if(vis[x])continue;
		vis[x]=1;
		for(long long i=head[x];i;i=tr[i].next){
			if(dis[tr[i].to]>dis[x]+tr[i].val){
				dis[tr[i].to]=dis[x]+tr[i].val;
				q.push({dis[tr[i].to],tr[i].to});
			}
		}
	}
	for(long long i=0;i<flag;i++){
		if(dis[i]<=l-1)ans1+=(l-1-dis[i])/flag+1;
		if(dis[i]<=r)ans2+=(r-dis[i])/flag+1;
	}
	cout<<ans2-ans1;
}