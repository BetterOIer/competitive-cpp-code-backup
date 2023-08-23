#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector<int> h;
bool vst[10000001]={1,1};
int p[10001];
int kk;
void prime(){
	for(int i=2;i<=10001;i++){
		if (vst[i]==0)	p[++kk]=i;	
		for(int j=1;j<=kk;j++){
			if(i*p[j]>10001)break;
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}	
	}
} 
void solve(){
    int a,b; cin>>a>>b;
    int k=b-a;
    if(k==1) return printf("-1\n"),void();
    for(int i=1;i<=kk;i++){
        if(k%p[i]==0) h.push_back(p[i]);
        while(k%p[i]==0) k/=p[i];
        if(!vst[k] || k==1) break;
    }
    if(k!=1) h.push_back(k);
    int ans=1e9;
    for(int x:h){
        int res=ceill(1.0*a/x)*x-a;
        ans=min(ans,res);
    }
    printf("%d\n",ans);
}
int main(){
    prime();
    int t=read();
    while(t--){
        solve();
        h.clear();
    }
}