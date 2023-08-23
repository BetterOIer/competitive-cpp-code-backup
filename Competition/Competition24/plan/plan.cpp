#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
int n,m,a,b,u,v;
long long ans=0;
vector<int>to[200005];
struct node{
	int to;
	int dang;
};
queue<node>Q;
bool cang[200005];
int main(){
	n=read(),m=read(),a=read(),b=read();
	for(int i = 1;i<=m;i++){
		u=read(),v=read();
		if((u==a&&v==b)||(u==b&&v==a))continue;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for(int i = 1;i<=n;i++){
		if(i==a||i==b)continue;
		for(int o = 1;o<=n;o++)cang[o]=false;
		cang[i]=true;
		Q.push((node){i,0});
		while(Q.size()>0){
			node now=Q.front();Q.pop();
			//cout<<now.to<<" "<<now.dang<<endl;
			for(int j = 0;j<to[now.to].size();j++){
				if((now.dang==a&&to[now.to][j]==b)||(now.dang==b&&to[now.to][j]==a)){
					cang[to[now.to][j]]=true;
					continue;
				}
				if(cang[to[now.to][j]]==true)continue;
				cang[to[now.to][j]]=true;
				//cout<<to[now.to][j]<<" " <<now.dang+(to[now.to][j]==b? b:(to[now.to][j]==a? a:0))<<endl;
				Q.push((node){to[now.to][j],now.dang+(to[now.to][j]==b? b:(to[now.to][j]==a? a:0))});
			}
		}
		for(int o = 1;o<=n;o++){
			if(!cang[o])ans++;
			//cout<<cang[o]<<" ";
		}
		//cout<<endl;
	}
	if(!ans)cout<<"kcm ak ioi qu le.";
	else cout<<ans/2;
} 
