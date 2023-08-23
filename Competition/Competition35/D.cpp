#include <bits/stdc++.h>
using namespace std;

const int maxn=200000;
struct req{
	int l,r,s,t,id;
}a[maxn+50];
int n,m,Q;
int u[maxn+50],v[maxn+50];
int dis[1000+50][1000+50];
int ans[maxn+50];

int main(){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> Q;
	for (int i=1;i<=m;i++) cin >> u[i] >> v[i];
	for (int i=1;i<=Q;i++){
		cin >> a[i].l >> a[i].r >> a[i].s >> a[i].t;
		a[i].id=i;
	}
	sort(a+1,a+Q+1,
		[&](const req &A,const req &B){
			return A.l>B.l;
		}
	);
	memset(dis,0x3f,sizeof(dis));
	int pos=1;
	for (int i=m;i>=1;i--){
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=i;
		for (int j=1;j<=n;j++)
			dis[u[i]][j]=dis[v[i]][j]=min(dis[u[i]][j],dis[v[i]][j]);
		for (;pos<=Q && a[pos].l==i;pos++)
			if (dis[a[pos].s][a[pos].t]<=a[pos].r) ans[a[pos].id]=1;
	}
	for (int i=1;i<=Q;i++){
		if (ans[i]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
