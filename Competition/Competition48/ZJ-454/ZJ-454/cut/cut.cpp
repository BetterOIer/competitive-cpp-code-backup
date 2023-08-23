#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int mod = 998244353;
int n,len=0;
struct node{
	bool can=true;
	vector<int>to;
}tree[100005];
int can[100005];
bool vis[100005];
int cal(int cnt){
	int pos=1;
	int ans=0;
	while(cnt){
		if(cnt&1){tree[can[pos]].can=false;ans+=can[pos];}
		else tree[can[pos]].can=true;
		cnt>>=1;
		pos++;
	}
	return ans;
}
int dfs(int pos){
	int npo=0;
	vis[pos]=true;
	for(int i:tree[pos].to){
		if(vis[i]) continue;
		npo+=dfs(i);
	}
	if(npo)tree[pos].can=false;
	if(tree[pos].can==false){
		return npo+1;
	}else{
		return 0;
	}
}
int main(){
    freopen("cut.in","r",stdin);
    freopen("cut.out","w",stdout);
	n=read();len=read();
	for(int i = 1;i<=len;i++){
		can[i]=read();
	}
	for(int i = 1,x,y;i<n;i++){
		x=read(),y=read();
		tree[x].to.push_back(y);
		tree[y].to.push_back(x);
	}
	int all=1<<len;
	long long ans=0;
	for(int i = 0;i<=all;i++){
		for(int j = 1;j<=n;j++)vis[j]=false;
		for(int j = 1;j<=n;j++)tree[j].can=true;
		int g = cal(i);
		tree[1].can=false;
		int f = dfs(1);
		ans=(ans+g*f)%mod;
	}
	cout<<ans;
    return 0;
}