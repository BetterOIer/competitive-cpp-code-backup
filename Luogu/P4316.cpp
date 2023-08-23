/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
struct node{
	int to;
	int val;
};
vector<node> ro[200003];
queue<int> Q;
int ru[100005],dg[100005];
double dp[100005];
int toposort(){
	Q.push(n);
	while(Q.size()){
		int now = Q.front();Q.pop();
		for(node to:ro[now]){
			dp[to.to]+=(dp[now]+to.val)/dg[to.to];
			if(!(--ru[to.to]))Q.push(to.to);
		}
	}return 0;
}
int main(){
	n=read(),m=read();
	for(int i = 1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		ro[v].push_back((node){u,w});
		ru[u]++,dg[u]++;
	}
	return toposort()*printf("%.2lf\n",dp[1])*0;
}