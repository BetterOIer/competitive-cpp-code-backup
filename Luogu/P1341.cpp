#include<iostream>
using namespace std;
int n,small;
char a[2];
int b[130][130];
int ru[130],fa[130];
char ans[1330];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x)
{
	for(int i=64;i<=125;i++)
	  if(b[x][i]){
	  	b[x][i]=b[i][x]=0;
	  	dfs(i);
	  }
	ans[n--]=x;
}
int main(){
	cin>>n;
	for(int i=64;i<=125;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		cin>>a;
		b[a[0]][a[1]]=b[a[1]][a[0]]=1;
		ru[a[0]]++;
		ru[a[1]]++;
		fa[find(a[0])]=find(a[1]);
	}
	int cnt=0;
	for(int i=64;i<=125;i++) if(fa[i]==i&&ru[i]) cnt++;
	if(cnt!=1){cout<<"No Solution"<<endl;return 0;}
	cnt=small=0;
	for(int i=64;i<=125;i++){
		if(ru[i]&1){
			cnt++;
			if(small==0)small=i;
		}
	}
	if(cnt&&cnt!=2){cout<<"No Solution"<<endl;return 0;}
    if(small==0) for(int i=64;i<=125;i++) if(ru[i]){small=i;break;}
    dfs(small);
    cout<<ans;
    return 0;
} 