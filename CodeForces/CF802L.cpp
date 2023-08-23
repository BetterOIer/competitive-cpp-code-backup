/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
const long long mod = 1e9+7;
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
vector<node>ro[100005];
long long n,b[100005],dg[100005],k[100005];
inline long long qpow(long long a,long long b){long long res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}
int pls(int x,int y){return (x+y)%mod;}
int dec(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1ll*x*y>=mod?1ll*x*y%mod:x*y;}
void dfs(int x,int fa){
	if(dg[x]==1&&x!=1){
		k[x]=b[x]=0;
		return;
	}
	int sumk=0;
	for(node i:ro[x]){
		int to=i.to,w=i.val;
		if(to==fa){
			b[x]=pls(b[x],w);
			continue;
		}
		dfs(to,x);
		b[x]=pls(b[x],b[to]);
		b[x]=pls(b[x],w);
		sumk=pls(sumk,k[to]);
	}
	k[x]=qpow(dec(dg[x],sumk),mod-2);
	b[x]=mul(b[x],k[x]);
}
int main(){
    n=read();
    for(long long i = 1,u,v,w;i<n;i++){
        u=read()+1,v=read()+1,w=read();
        ro[u].push_back((node){v,w});
        ro[v].push_back((node){u,w});
        dg[u]++,dg[v]++;
    }
    dfs(1,0);
    printf("%lld\n",b[1]);
}