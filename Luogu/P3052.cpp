#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
int a[20];
int pr[1<<20];
int dp[1<<20];
int main(){
    for(int i = 1;i<(1<<20);i++)dp[i]=2147483647;
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1)))pr[i]+=a[j];
		}
	}
    for(int i = 1;i<(1<<n);i++){
        for(int j = i;j;j=(j-1)&i){
            if(pr[j]>m)continue;
            dp[i]=min(dp[i],dp[i-j]+1);
        }
    }
    cout<<dp[(1<<n)-1];
}