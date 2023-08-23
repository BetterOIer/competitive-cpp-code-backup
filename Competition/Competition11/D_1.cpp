#include<bits/stdc++.h>
using namespace std;
int n,ANS=0;
struct node{
	int data,l=-1,r=-1;
}t[1000005];
bool dfs(int x,int y){
	if(x==-1&&y==-1) return 1;
	if(x==-1||y==-1) return 0;
	if(t[x].data!=t[y].data) return 0;
	if(dfs(t[x].l,t[y].r)&&dfs(t[x].r,t[y].l)) return 1;
} 
int cnt(int x){
	if(x==-1) return 0;
	return cnt(t[x].l)+cnt(t[x].r)+1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i].data;
	for(int i=1;i<=n;i++) cin>>t[i].l>>t[i].r;
	for(int i=1;i<=n;i++){
		if(dfs(t[i].l,t[i].r)) ANS=max(cnt(i),ANS);
	}
	cout<<ANS;
	return 0;
} 