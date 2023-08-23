#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, root, step, last = 0, ans = 0;
inline int Read()
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
struct node
{
    int ch[2], size, sz, cnt;
} tree[2000000];

int update(int x)
{
    tree[x].size = tree[tree[x].ch[0]].size + tree[tree[x].ch[1]].size + tree[x].cnt;
    return 0;
}
int rotate(int &x, int gx)
{
    int son = tree[x].ch[gx ^ 1];
    tree[x].ch[gx ^ 1] = tree[son].ch[gx];
    tree[son].ch[gx] = x;
    tree[son].size = tree[x].size;
    update(x);
    x = son;
    return 0;
}
int matain(int &x, int gx)
{
    if (gx)
    {
        if (tree[tree[x].ch[0]].size < tree[tree[tree[x].ch[1]].ch[1]].size)
            rotate(x, 0);
        else if (tree[tree[x].ch[0]].size < tree[tree[tree[x].ch[1]].ch[0]].size)
        {
            rotate(tree[x].ch[1], 1);
            rotate(x, 0);
        }
        else
            return 0;
    }
    else
    {
        if (tree[tree[x].ch[1]].size < tree[tree[tree[x].ch[0]].ch[0]].size)
            rotate(x, 1);
        else if (tree[tree[x].ch[1]].size < tree[tree[tree[x].ch[0]].ch[1]].size)
        {
            rotate(tree[x].ch[0], 0);
            rotate(x, 1);
        }
        else
            return 0;
    }
    matain(tree[x].ch[1], 1);
    matain(tree[x].ch[0], 0);

    return 0;
}
int add(int &x, int sz)
{
    if (x == 0)
    {
        x = ++step;
        tree[x].cnt = 1;
        tree[x].size = 1;
        tree[x].sz = sz;
        return 0;
    }
    tree[x].size++;
    if (tree[x].sz == sz)
    {
        tree[x].cnt++;
        return 0;
    }
    else if (tree[x].sz < sz)
        add(tree[x].ch[1], sz);
    else
        add(tree[x].ch[0], sz);
    matain(x, tree[x].sz < sz);
    return 0;
}
int del(int &x, int sz, int sl)
{
    tree[x].size -= sl;
    if (tree[x].sz == sz)
    {
        if (tree[x].cnt > sl)
            tree[x].cnt -= sl;
        else if ((!tree[x].ch[0]) || (!tree[x].ch[1]))
            x = tree[x].ch[0] + tree[x].ch[1];
        else
        {
            int temp = tree[x].ch[1];
            while (tree[temp].ch[0])
                temp = tree[temp].ch[0];
            tree[x].sz = tree[temp].sz;
            tree[x].cnt = tree[temp].cnt;
            del(tree[x].ch[1], tree[temp].sz, tree[temp].cnt);
        }
        return 0;
    }
    if (tree[x].sz < sz)
        del(tree[x].ch[1], sz, sl);
    else
        del(tree[x].ch[0], sz, sl);
    return 0;
}
int rankl(int sz)
{
    int x = root, res = 0;
    while (x)
    {
        if (tree[x].sz == sz)
            return res + tree[tree[x].ch[0]].size + 1;
        if (tree[x].sz < sz)
        {
            res += tree[tree[x].ch[0]].size + tree[x].cnt;
            x = tree[x].ch[1];
        }
        else
            x = tree[x].ch[0];
    }
    return res + 1;
}
int arrank(int wz)
{
    int x = root;
    while (x)
    {
        if (tree[x].cnt + tree[tree[x].ch[0]].size < wz)
        {
            wz -= tree[x].cnt + tree[tree[x].ch[0]].size;
            x = tree[x].ch[1];
        }
        else if (tree[tree[x].ch[0]].size < wz)
            return tree[x].sz;
        else
            x = tree[x].ch[0];
    }
    return 0;
}
int qianqu(int sz)
{
    int x = root, maxx = -2147483647;
    while (x)
    {
        if (tree[x].sz < sz && tree[x].sz > maxx)
            maxx = tree[x].sz;
        if (tree[x].sz < sz)
            x = tree[x].ch[1];
        else
            x = tree[x].ch[0];
    }
    return maxx;
}
int houqu(int sz)
{
    int x = root, minn = 2147483647;
    while (x)
    {
        if (tree[x].sz > sz && tree[x].sz < minn)
            minn = tree[x].sz;
        if (tree[x].sz <= sz)
            x = tree[x].ch[1];
        else
            x = tree[x].ch[0];
    }
    return minn;
}
int main()
{
    n = Read();
    m = Read();
    for (int p, i = 1; i <= n; i++)
    {
        p = Read();
        add(root, p);
    }
    for (int k, temp, i = 1; i <= m; i++)
    {
        temp = Read();
        k = Read() ^ last;
        if (temp == 1)
            add(root, k);
        else if (temp == 2)
            del(root, k, 1);
        else if (temp == 3)
            last = rankl(k);
        else if (temp == 4)
            last = arrank(k);
        else if (temp == 5)
            last = qianqu(k);
        else
            last = houqu(k);
        if (temp >= 3)
            ans ^= last;
    }
    cout << ans;
    return 0;
}