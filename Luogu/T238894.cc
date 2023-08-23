#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sx,sy;
ll ne[1005][1005];
ll now[1005][1005];
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&sy,&sx);
	sx=n-sx+1;
	string q;
	cin>>q;
	for(ll w=1;w<=m;w++){
		char flag;
		flag=q[w-1];
		//cout<<flag<<endl;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==sx && j==sy){
					ne[i][j]=0;
					continue;
				}
				ne[i][j]++;
				now[i][j]+=ne[i][j];
			}
		}
		if(flag=='N') sx--;
		else if(flag=='S') sx++;
		else if(flag=='E') sy++;
		else if(flag=='W') sy--;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<now[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}