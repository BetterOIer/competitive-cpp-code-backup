#include <bits/stdc++.h>
using namespace std;
int g[510][510], ans, f[510][510];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = ++ans;
    for (int i = 1; i <= m; i++)
    {
        int a, b, r, opt;
        scanf("%d %d %d %d", &a, &b, &r, &opt);
        if (opt == 0)
        {
            for (int i = a - r; i <= a + r; i++)
                for (int j = b - r; j <= b + r; j++)
                    f[a - b + j][a + b - i] = g[i][j];
            for (int i = a - r; i <= a + r; i++)
                for (int j = b - r; j <= b + r; j++)
                    g[i][j] = f[i][j];
        }
        else
        {
            for (int i = a - r; i <= a + r; i++)
                for (int j = b - r; j <= b + r; j++)
                    f[a + b - j][b - a + i] = g[i][j];
            for (int i = a - r; i <= a + r; i++)
                for (int j = b - r; j <= b + r; j++)
                    g[i][j] = f[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
    return 0;
}
