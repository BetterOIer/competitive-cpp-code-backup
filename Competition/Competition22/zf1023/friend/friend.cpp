#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
	int rmb;
	int rp;
	int time;
}vill[105],dp[1000004];
int main(){
	freopen("friend.in","r",stdin);
	freopen("friend.out","w",stdout);
	int n=read();
	int T=0;
	for(int i = 1;i<=n;i++){
		vill[i].rmb=read(),vill[i].rp=read(),vill[i].time=read();
		T+=vill[i].time;
	}
	int m=read(),RP=read(),MAXf=0,MINt=0;
	for(int i = 1;i<=n;i++){
		for(int j = T;j>=vill[i].time;j--){
			if(dp[j-vill[i].time].rmb+vill[i].rmb<=m&&dp[j-vill[i].time].rp+vill[i].rp<=RP){
				if(dp[j].time<dp[j-vill[i].time].time+1){
					dp[j].rmb=dp[j-vill[i].time].rmb+vill[i].rmb;
					dp[j].rp=dp[j-vill[i].time].rp+vill[i].rp;
					dp[j].time=dp[j-vill[i].time].time+1;
				}
			}
		}
	}
	for(int i = 1;i<=T;i++) {
		if(MAXf<dp[i].time){
			MAXf=dp[i].time;
			MINt=i;
		}
	}
	cout<<MINt<<endl;
	fclose(stdin);
	fclose(stdout);
}
