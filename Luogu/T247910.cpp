#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sb{
	ll v;
	int u;
}a[1005];
int n,g[1005];
ll ans[1005][1000];
bool pd[1005];
void chen(ll b[],int &k,int x){
	if(a[x].u==0)return;
	if(a[x].v==0){
		b[0]=4;
		return;
	}
	ll c=a[x].v;
	for(int i=1;i<=k;i++){
		b[i]=b[i]*c;
	}
	for(int i=1;i<=k;i++){
		if(b[i]>=10){
			b[i+1]+=b[i]/10;
			b[i]=b[i]%10;
		}
	}
	while(b[k+1]||b[k+2]||b[k+3]||b[k+4]||b[k+5]||b[k+6]){
		k++;
		if(b[k]>=10){
			b[k+1]+=b[k]/10;
			b[k]=b[k]%10;
		}
	}
	chen(b,k,a[x].u);
}
void jia(ll b[],int k){
	if(b[0]==4)return;
	if(k>g[0])g[0]=k;
	for(int i=1;i<=g[0];i++){
		ans[0][i]+=b[i];
		ans[0][i+1]+=ans[0][i]/10;
		ans[0][i]%=10;
	}
	while(ans[0][g[0]+1])g[0]++;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int o,l,r;
		cin>>o>>l>>a[l].v>>r>>a[r].v;
		a[l].u=o,a[r].u=o;
//		if(l==0&&a[l].v==0&&r==0&&a[r].v==0)pd[o]=0;
//		else pd[o]=1;
	}
	for(int i=1;i<=n;i++){
//		if(!pd[i]){
			ll k=a[i].v;
			ans[i][0]=1;
			for(int j=1;k;j++){
				ans[i][j]=k%10;
				k/=10;
				g[i]=j;
			}
			chen(ans[i],g[i],a[i].u);
//			for(int q=g[i];q>=1;q--){
//				cout<<ans[i][q];
//			}
//			cout<<endl;
			jia(ans[i],g[i]);
//		}
	}
	for(int i=g[0];i>=1;i--){
		cout<<ans[0][i];
	}
	return 0;
}