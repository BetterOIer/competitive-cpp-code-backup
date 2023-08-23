//*** Le vent se lève, il faut tenter de vivre !***
#include <bits/stdc++.h>
#define maxn 100100
#define ll long long
using namespace std;
ll tree[maxn*4],a[maxn];int fa[maxn],m,n,q,l,r,t;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(int x,ll y){while(x<=n)tree[x]+=y,x+=(x&-x);}
ll qry(int x){ll r=0;while(x)r+=tree[x],x-=(x&-x);return r;}
int main(){
	scanf("%d",&n);for (int i=1;i<=n;i++)
	scanf("%lld",&a[i]),add(i,a[i]),fa[i]=i;scanf("%d",&m);fa[n+1]=n+1;
	while(m--){scanf("%d%d%d",&q,&l,&r);if (l>r) swap(l,r); 
		if (q==1) printf("%lld\n",qry(r)-qry(l-1));
		else for (int i=l;i<=r;add(i,(t=(int)sqrt(a[i]))-a[i]),a[i]=t,fa[i]=(a[i]<=1)?i+1:i,i=(find(i)==i)?i+1:fa[i]);
	}
}