#include <bits/stdc++.h>
using namespace std;

const int T = 31, N = 100010;
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = (x << 3) + (x << 1) + (c ^ 48);
    return x * f;
}
int n, t, m;
int laz[T][N << 2], sum[T][N << 2];

void pushup(int i, int x)
{
    sum[i][x] = sum[i][((x) << 1)] + sum[i][((x) << 1 | 1)];
}

void build(int i, int x, int l, int r)
{
    if (l == r)
    {
        sum[i][x] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(i, ((x) << 1), l, mid);
    build(i, ((x) << 1 | 1), mid + 1, r);
    pushup(i, x);
}

void pushdown(int i, int x)
{
    if (laz[i][x] == -1)
    {
        sum[i][((x) << 1)] = sum[i][((x) << 1 | 1)] = 0;
        laz[i][((x) << 1)] = laz[i][((x) << 1 | 1)] = -1;
    }
    else
    {
        sum[i][((x) << 1)] = sum[i][((x) << 1 | 1)] = laz[i][x];
        laz[i][((x) << 1)] = laz[i][((x) << 1 | 1)] = laz[i][x];
    }
    laz[i][x] = 0;
}

void update(int i, int x, int l, int r, int ls, int rs, int v)
{
    if (l > rs || r < ls)
        return;
    if (l >= ls && r <= rs)
    {
        sum[i][x] = v;
        if (!v)
            laz[i][x] = -1;
        else
            laz[i][x] = v;
        return;
    }
    if (laz[i][x])
        pushdown(i, x);
    int mid = (l + r) >> 1;
    if (ls <= mid)
        update(i, ((x) << 1), l, mid, ls, rs, v);
    if (rs > mid)
        update(i, ((x) << 1 | 1), mid + 1, r, ls, rs, v);
    pushup(i, x);
}

int query(int i, int x, int l, int r, int ls, int rs)
{
    if (l > rs || r < ls)
        return 0;
    if (l >= ls && r <= rs)
        return sum[i][x];
    if (laz[i][x])
        pushdown(i, x);
    int mid = (l + r) >> 1;
    return query(i, ((x) << 1), l, mid, ls, rs) + query(i, ((x) << 1 | 1), mid + 1, r, ls, rs);
}

int main()
{
    n=read(), t=read(), m=read();
    build(1, 1, 1, n);
    char opt;
    int l, r, v;
    for (int i = 1; i <= m; ++i)
    {
        cin>>opt;
        l=read(),r=read();
        if (l > r)
            swap(l, r);
        if (opt == 'C')
        {
            v=read();
            for (int k = 1; k <= t; ++k)
                if (k != v)
                    update(k, 1, 1, n, l, r, 0);
                else
                    update(k, 1, 1, n, l, r, 1);
        }
        else
        {
            int ans = 0;
            for (int k = 1; k <= t; ++k)
                if (query(k, 1, 1, n, l, r))
                    ++ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}