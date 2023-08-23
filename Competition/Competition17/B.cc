#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
ll g[1000006],ans[1000006],tot,anss=1e9;
ll n,m;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int l=read(),r=read();
		ll v=read();
		g[l]+=1;
		g[r+1]-=1;
		ans[l]+=v;
		ans[r+1]-=v;
		tot+=v;
	}
	for(int i=1;i<=n;i++){
		g[i]+=g[i-1];
		ans[i]+=ans[i-1];
		anss=min(anss,ans[i]);
		if(g[i]==0){
			cout<<tot<<endl;
			return 0;
		}
	}
	cout<<tot-anss;
	return 0;
}