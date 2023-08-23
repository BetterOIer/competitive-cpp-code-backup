#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long num[10000005],n,q,ans[10000005],b[10000005];
bool a[10000005]={1,1};
long long k, maxn;
const long long mod = 1e9+7;
void solve(long long x){
    for(long long i = 1;i*x<=maxn;i++){
        ans[x]=(ans[x]+num[i*x])%mod;
    }
}
int main(){
    n=read(),q=read();
    for(long long i = 1,w;i<=n;i++){
        w=read();
        num[w]++;
        maxn=max(maxn,w);
    }
    for(long long i=2;i<=maxn;i++)
	{
		if (a[i]==0){
            b[++k]=i;
            solve(i);
        }
		for(long long j=1;j<=k;j++)
		{
			if(i*b[j]>maxn)break;
			a[i*b[j]]=1;
			if(i%b[j]==0)break;
		}	
	}
    for(long long i = 1;i<=10000000;i++){
        ans[i]=(ans[i-1]+ans[i])%mod;
    }
    for(long long i = 1,l,r;i<=q;i++){
        l=read(),r=read();
        cout<<((ans[r]-ans[l-1])%mod+mod)%mod<<endl;
    }
}