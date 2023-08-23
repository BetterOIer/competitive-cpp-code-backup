/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 没有BUG的代码是不完美的！ --Sodium_Sulfate
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int t,n,p[200005],r[200005];
long long a[200005],b[200005];
vector<int> g[200005];
set<long long> s;
map<long long,int> mp;
void dfs(int x){
	for(auto i:g[x]){
		if(i!=p[x]){
			a[i]+=a[x],b[i]+=b[x],s.insert(b[i]);
			mp[b[i]]=s.size()-1;
			auto it=s.upper_bound(a[i]);
			it--,r[i]=mp[*it];
			dfs(i);s.erase(b[i]);
		}
	}
}
int main(){
	t=read();
	while(t--){
		s.clear();mp.clear();
		n=read();
		for(int i=1;i<=n;i++) {g[i].clear();r[i]=a[i]=b[i]=0;}
		for(int i=2;i<=n;i++){
			p[i]=read(),a[i]=read(),b[i]=read();
			g[p[i]].push_back(i);
		}
		s.insert(0);
		dfs(1);for(int i=2;i<=n;i++) printf("%d ",r[i]);
		printf("\n");
	}
	return 0;
}
