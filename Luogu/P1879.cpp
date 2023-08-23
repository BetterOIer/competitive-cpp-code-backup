#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
int graph[14][14];
int dp[13][1<<12];
int F[13];
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            graph[i][j]=read();
            F[i] = (F[i] << 1) + graph[i][j];
        }
    }
    dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (1 << m); j++) {
			if ((!(j & (j << 1))) && (!(j & (j >> 1))) && ((j & F[i]) == j)) {
				for (int k = 0; k < (1 << m); k++) {
					if ((k & j) == 0) {
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000000;
					}
				}
			}
		}
	}
    int ans=0;
    for(int i = 0;i<(1<<m);i++){
        ans=(ans+dp[n][i])%100000000;
    }
    cout<<ans<<endl;
}