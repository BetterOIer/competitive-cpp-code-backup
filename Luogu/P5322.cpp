#include <iostream>
#include <algorithm>
using namespace std;
int s, n, m, ans, val[110][110];
int dp[20002];
int main(){
    scanf("%d%d%d", &s, &n, &m);
    for (int i = 1; i <= s; ++i){
        for (int j = 1; j <= n; ++j){
            scanf("%d", &val[j][i]);
        }
    }
    for (int i = 1; i <= n; ++i) sort(val[i] + 1, val[i] + 1 + s);
    for (int i = 1; i <= n; ++i){
        for (int j = m; j >= 0; --j){
            for (int k = 1; k <= s; ++k){
                if (j > val[i][k] * 2){
                    dp[j] = max(dp[j - val[i][k] * 2 - 1] + k * i, dp[j]);
                }
            }
        }
    }
    for (int i = 0; i <= m; ++i) ans = max(ans, dp[i]);
    cout << ans;
    
}