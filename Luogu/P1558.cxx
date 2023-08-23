#include <cstdio>
#include <string>
int l, t, o;
int a[1000005], lazy[1000005];
long long lower(int x)
{
    long long temp = 1;
    for (int lmq = 0; lmq < x; lmq++)
    {
        temp *= 2;
    }
    return temp;
}
void pushdown(int pos)
{
    if (lazy[pos])
    {
        lazy[pos << 1] = lazy[pos];
        lazy[(pos << 1 | 1)] = lazy[pos];
        a[pos << 1] = lazy[pos];
        a[(pos << 1 | 1)] = lazy[pos];
        lazy[pos] = 0;
    }
}
void pushup(int pos)
{
    a[pos] = a[pos << 1] | a[(pos << 1 | 1)];
}
void build(int left, int right, int pos)
{
    if (left == right)
    {
        a[pos] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(left, mid, pos << 1);
    build(mid + 1, right, (pos << 1 | 1));
    pushup(pos);
}
void update(int l, int r, int c, int left, int right, int pos)
{
    if (l <= left && r >= right)
    {
        pushdown(pos);
        long long tmp = lower(c - 1);
        a[pos] = tmp;
        lazy[pos] = tmp;
        return;
    }
    pushdown(pos);
    int mid = (left + right) / 2;
    if (l <= mid)
    {
        update(l, r, c, left, mid, pos << 1);
    }
    if (mid < r)
    {
        update(l, r, c, mid + 1, right, (pos << 1 | 1));
    }
    pushup(pos);
}
long long query(int l, int r, int left, int right, int pos)
{
    if (l <= left && right <= r)
    {
        return a[pos];
    }
    pushdown(pos);
    int mid = (left + right) / 2;
    long long temp = 0;
    if (l <= mid)
    {
        temp = temp | query(l, r, left, mid, pos << 1);
    }
    if (mid < r)
    {
        temp = temp | query(l, r, mid + 1, right, (pos << 1 | 1));
    }
    return temp;
}
void f(long long x)
{
    int res = 0;
    for (; x != 0;)
    {
        if (x % 2 == 1)
            res++;
        x = x / 2;
    }
    printf("%d\n", res);
    return;
}
int main()
{
    scanf("%d%d%d", &l, &t, &o);
    build(1, l, 1);
    for (int i = 0; i < o; i++)
    {
        char q[3];
        scanf("%s", q);
        if (q[0] == 'C')
        {
            int c1, c2, c3;
            scanf("%d%d%d", &c1, &c2, &c3);
            if (c1 > c2)
            {
                int chicken = c1;
                c1 = c2;
                c2 = chicken;
            }
            update(c1, c2, c3, 1, l, 1);
        }
        else
        {
            int c1, c2;
            scanf("%d%d", &c1, &c2);
            if (c1 > c2)
            {
                int chicken = c1;
                c1 = c2;
                c2 = chicken;
            }
            long long ans = query(c1, c2, 1, l, 1);
            f(ans);
        }
    }
    return 0;
}