#include <iostream>
using namespace std;
const int Maxn = 1e5 + 200 + 10;
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
struct node
{
    int ch[2];
    int size, val, dat;
} t[Maxn];
int n, m, q, cnt;
int root, xxx, yyy, xx, yy, tot;
string s[Maxn];
void update(int id)
{
    t[id].size = t[t[id].ch[0]].size + t[t[id].ch[1]].size + 1;
}
int New(int r)
{
    t[++tot].size = 1, t[tot].val = r, t[tot].dat = rand();
    return tot;
}
void split(int id, int r, int &x, int &y)
{
    if (!id)
        x = y = 0;
    else
    {
        if (r <= t[t[id].ch[0]].size)
        {
            y = id;
            split(t[id].ch[0], r, x, t[id].ch[0]);
        }
        else
        {
            x = id;
            split(t[id].ch[1], r - t[t[id].ch[0]].size - 1, t[id].ch[1], y);
        }
        update(id);
    }
}
int merge(int x, int y)
{
    if (!x || !y)
        return x + y;
    if (t[x].dat < t[y].dat)
    {
        t[x].ch[1] = merge(t[x].ch[1], y);
        update(x);
        return x;
    }
    t[y].ch[0] = merge(x, t[y].ch[0]);
    update(y);
    return y;
}
void insert(int r, int id)
{
    split(root, r, xxx, yyy);
    root = merge(xxx, merge(New(id), yyy));
}
void query(int r)
{
    split(root, r, xxx, yyy);
    split(yyy, 1, xx, yy);
    cout << s[t[xx].val] << endl;
    root = merge(xxx, merge(xx, yy));
}
int main()
{
    srand(20041029);
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[++cnt];
        insert(i - 1, cnt);
    }
    m = read();
    while (m--)
    {
        cin >> s[++cnt];
        int x = read();
        insert(x, cnt);
    }
    q = read();
    while (q--)
    {
        int x = read();
        query(x);
    }
    return 0;
}
