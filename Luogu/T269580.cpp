#include <bits/stdc++.h>
using namespace std;
int rmb[105],rp[105],timel[105],n,m,r,dp[105][105][2];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) cin>>rmb[i]>>rp[i]>>timel[i];
	cin>>m>>r;
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= rmb[i]; --j)
			for (int k = r; k >= rp[i]; --k) {
				if (dp[j][k][0] < dp[j-rmb[i]][k-rp[i]][0]+1) {
					dp[j][k][0] = dp[j-rmb[i]][k-rp[i]][0]+1;
					dp[j][k][1] = dp[j-rmb[i]][k-rp[i]][1]+timel[i];
				}
				else if (dp[j][k][0] == dp[j - rmb[i]][k-rp[i]][0]+1){
					dp[j][k][1] = min(dp[j][k][1], dp[j-rmb[i]][k-rp[i]][1]+timel[i]);
                }
			}
	cout<<dp[m][r][1]<<endl;
}