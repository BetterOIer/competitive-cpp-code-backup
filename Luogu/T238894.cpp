#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,y,x;
ll ne[1005][1005];
ll nw[1005][1005];
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&y,&x);
	y=n-y+1;
	string s;
	cin>>s;
	for(long long w=1;w<=m;w++){
		char flag;
		flag=s[w-1];
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i==y && j==x){
					ne[i][j]=0;
					continue;
				}
				ne[i][j]++;
				nw[i][j]+=ne[i][j];
			}
		}
		if(flag=='N') y--;
		else if(flag=='S') y++;
		else if(flag=='E') x++;
		else if(flag=='W') x--;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			cout<<nw[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}