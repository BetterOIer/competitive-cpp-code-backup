#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};
queue<pair<int, int>> q;
int f[500][500];
bool zgm[500][500];
int main()
{
    int n, m, x, y;
    memset(f, -1, sizeof(f));
    memset(zgm, false, sizeof(zgm));
    cin >> n >> m >> x >> y;
    f[x][y] = 0;
    zgm[x][y] = true;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int u = xx + dx[i], v = yy + dy[i];
            if (u < 1 || u > n || v < 1 || v > m || zgm[u][v])
                continue;
            zgm[u][v] = true;
            q.push(make_pair(u, v));
            f[u][v] = f[xx][yy] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%-5d", f[i][j]);
        printf("\n");
    }
    return 0;
}