/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
const int N=1e6+10;
int n,sz[N]; vector<int>t[N];
long long f[N][2];
void dfs(int u,int fa){
	vector<long long> a;
	long long sum=f[u][0]; sz[u]=1;
	a.push_back(f[u][1]-f[u][0]);
	for(auto v:t[u]) if(v!=fa){
		dfs(v,u); sz[u]^=sz[v]; sum+=f[v][0];
		if(sz[v]) a.push_back(f[v][1]-f[v][0]);
	}
	sort(a.begin(),a.end());
	int m=-a.size();
	for(int i = 1;i<=a.size();i++){
		if(abs(m)<=1) f[u][m+(m<0)]=sum;
		sum+=a[i-1]; m+=2;
	}
	if(abs(m)<=1) f[u][m+(m<0)]=sum;
}
int main() {
	n=read();
	for(int i = 1;i<=n;i++) f[i][0]=read(),f[i][1]=read();
	for(int i = 1;i<n;i++){
		int u=read(),v=read();
		t[u].push_back(v); t[v].push_back(u);
	}
	dfs(1,0);
	cout<<min(f[1][0],f[1][n&1]);
}