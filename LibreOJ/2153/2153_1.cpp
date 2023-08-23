#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define ll long long
ll dp[10][1 << 9][100];
int cnt[1 << 9];
bool check1(int n) {
    while (n) {
        while (n % 2 == 0)
            n >>= 1;

        n >>= 1;

        if (n & 1)
            return false;
    }

    return true;
}
bool check2(int x, int y) {
    if (x & y)
        return false;

    return check1(x | y);
}
int main() {
    for (int i = 1; i < 1 << 9; i++)
        cnt[i] = cnt[i >> 1] + i % 2;

    int n, K;
    cin >> n >> K;

    for (int i = 0; i < 1 << n; i++)
        if (cnt[i] <= K && check1(i)) {
            dp[1][i][cnt[i]] = 1;
        }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 1 << n; j++) {
            if (cnt[j] > K)
                continue;

            for (int k = 0; k < 1 << n; k++) {
                for (int p = cnt[j] + cnt[k]; p <= K; p++) {
                    if (check2(j, k))
                        dp[i][j][p] += dp[i - 1][k][p - cnt[j]];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 1 << n; i++) ans += dp[n][i][K];
    cout << ans;
}