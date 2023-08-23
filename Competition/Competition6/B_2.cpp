#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int a[N], b[N];
int main()
{
    int x, y, n, m;
    scanf("%d%d%d%d", &x, &y, &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
        b[i] += b[i - 1];
    }
    for (int i = n - 1; i >= 1; i--)
        a[i] = min(a[i + 1], a[i]);
    for (int i = m - 1; i >= 1; i--)
        b[i] = min(b[i + 1], b[i]);
    int ans = 2e9, t = abs(x - y);
    for (int i = 0; i <= n; i++)
        if (t - i <= m)
            ans = min(ans, max(a[i], b[t - i]));
    printf("%d\n", ans);
    return 0;
}