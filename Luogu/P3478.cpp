// TODO
#include<iostream>
#include<vector>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const long long maxn=200005;
long long n;
vector<long long> a[maxn];
long long size[maxn],f[maxn];
long long depsum[maxn];

void dfs1(long long pos,long long fa){
	size[pos]=1;
	for(long long to:a[pos]){
		if(to==fa)continue;
		dfs1(to,pos);
		size[pos]+=size[to];
		f[pos]+=f[to];
	}
	f[pos] += size[pos];
}
void dfs2(long long pos,long long fa){
	depsum[pos]=depsum[fa]+n-2*size[pos];
	for(long long to:a[pos]){
		if(to==fa)continue;
		dfs2(to,pos);
	}
}
int main(){
    n=read();
    for(long long i = 1,x,y;i<n;i++){
		x=read(),y=read();
        a[x].push_back(y);
        a[y].push_back(x);
    }
	dfs1(1,0);
	depsum[1]=f[1];
	for(long long to:a[1]){
		dfs2(to,1);
	}
	long long mass=0;
	for(long long i = 1;i<=n;i++){
		if(mass<depsum[i]){
			mass=depsum[i];
		}
	}
	cout<<mass;
}