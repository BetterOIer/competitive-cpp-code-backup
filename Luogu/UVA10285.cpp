/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 人生，一半是现实，一半是梦想。一念花开，一念花落。
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
string name;
int T,n,m,map[101][101],step[101][101],maxn=0,walk[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int a,int b,int k){
    for(int p,q,i=0;i<4;i++){
        p=a+walk[i][0],q=b+walk[i][1];
        if(p>=1&&p<=n&&q>=1&&q<=m&&k+1>step[p][q]&&map[a][b]<map[p][q]){
            step[p][q]=k+1;
            dfs(p,q,k+1);
        }
    }
}
int main(){
	T=read();
	while(T--){
	    maxn=1;
		cin>>name;
        n=read(),m=read();
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) step[i][j]=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) map[i][j]=read();
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!step[i][j])  dfs(i,j,1);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) maxn=max(maxn,step[i][j]);
        cout<<name<<": "<<maxn<<endl;
	}
}
