#include<iostream>
#include<map>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
map<int, int> reff;
int n, m, sum;
int v[200005], w[200005], tot;
int dp[200005];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b; i <= n; i++) scanf("%d%d", &a, &b), reff[b - a]++, sum += a;
    memset(dp, 0x3f, sizeof dp), dp[sum] = 0;
    for (auto x : reff) {
        int tv = x.first, s = x.second, k = 1;
        while (k <= s) v[++tot] = k * tv, w[tot] = k, s -= k, k <<= 1;
		if (s > 0) v[++tot] = s * tv, w[tot] = s;
    }
	n = tot;
    for (int i = 1; i <= n; i++) {
        if (v[i] > 0) for (int j = m; j >= v[i]; j--) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        else for (int j = 0; j <= m + v[i]; j++) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
	}
    for (int i = 0; i <= m; i++) printf("%d\n", dp[i] == 0x3f3f3f3f ? -1 : dp[i]);
}