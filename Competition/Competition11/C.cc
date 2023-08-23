#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 505, maxM = 205;
int n, m, mm, ans = 1e9, t[maxN], g[maxN][maxM];
int main() {
    scanf("%d%d", &n, &m); mm = m + m;
    for (int i = 1; i <= n; i++) { scanf("%d", &t[i]); }
    sort(t + 1, t + n + 1); 
    for (int i = 1; i <= n; i++) {
    	g[i][0] = 1e9;
    	for (int j = 0; j <= min(t[i] - t[i - 1] - m, m - 1); j++) { g[i][0] = min(g[i][0], g[i - 1][j]); }
    	for (int j = 1; j < mm; j++) { g[i][j] = min(g[i][j - 1], t[i] + j - t[i - 1] - m >= 0 && t[i] + j - t[i - 1] - m < mm ? g[i - 1][t[i] + j - t[i - 1] - m] : (int) 1e9); }
    	for (int j = 0; j < mm; j++) { g[i][j] = min(g[i][j], t[i] + j - t[i - 1] < mm ? g[i - 1][t[i] + j - t[i - 1]] : (int) 1e9) + j; }
    }
    for (int i = 0; i < m; i++) { ans = min(ans, g[n][i]); }
    printf("%d\n", ans);
    return 0;
}