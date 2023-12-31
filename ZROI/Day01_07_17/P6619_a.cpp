// Problem : P6619 [省选联考 2020 A/B 卷] 冰火战士
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6619
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <algorithm>
#include <iostream>
using namespace std;
struct query
{
    int op;
    int k;
    int t, x, y;
} a[205];
struct BIT
{
    long long a[2000005];
    int n;
    void init(int x) { n = x; }
    int lowbit(int x) { return x & (-x); }
    void add(int x, int y)
    {
        while (x <= n)
            a[x] += y, x += lowbit(x);
    }
    long long query(int x)
    {
        long long ans = 0;
        while (x)
            ans += a[x], x -= lowbit(x);
        return ans;
    }
    long long get(int x) { return a[x]; }
} tr0, tr1;
long long sum1;
int p[205], cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].op;
        if (a[i].op == 1)
        {
            cin >> a[i].t >> a[i].x >> a[i].y;
            p[++cnt] = a[i].x;
        }
        else
            cin >> a[i].k;
    }
    sort(p + 1, p + cnt + 1);
    cnt = unique(p + 1, p + cnt + 1) - p - 1;
    for (int i = 1; i <= n; i++)
        if (a[i].op == 1)
            a[i].x = lower_bound(p + 1, p + cnt + 1, a[i].x) - p;
    tr0.init(cnt), tr1.init(cnt);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].op == 1)
        {
            if (!a[i].t)
                tr0.add(a[i].x, a[i].y);
            else
                tr1.add(a[i].x + 1, a[i].y), sum1 += a[i].y;
        }
        else
        {
            int k = a[i].k;
            if (!a[k].t)
                tr0.add(a[k].x, -a[k].y);
            else
                tr1.add(a[k].x + 1, -a[k].y), sum1 -= a[k].y;
        }
        for(int j = 0;j<=cnt;j++)cout<<tr0.get(j)<<" ";
        cout<<endl;
        for(int j = 0;j<=cnt;j++)cout<<tr1.get(j)<<" ";
        cout<<endl;
        long long s0 = 0, s1 = sum1;
        long long f1 = 0, f2 = 0;
        int p1 = 0, p2 = 0;
        for (int i = 20; i >= 0; i--)
        {
            int np = p1 + (1 << i), ns0 = s0 + tr0.get(np), ns1 = s1 - tr1.get(np);
            cout<<ns0<<" "<<ns1<<endl;
            if (np > cnt)
                continue;
            if (ns0 < ns1)
            {
                p1 = np;
                s0 = ns0, s1 = ns1;
            }
        }
        f1 = s0, s0 = 0, s1 = sum1;
        if (p1 < cnt)
        {
            f2 = min(tr0.query(p1 + 1), sum1 - tr1.query(p1 + 1));
            for (int i = 20; i >= 0; i--)
            {
                int np = p2 + (1 << i), ns0 = s0 + tr0.get(np), ns1 = s1 - tr1.get(np);
                if (np > cnt)
                    continue;
                if (ns0 < ns1)
                {
                    p2 = np;
                    s0 = ns0, s1 = ns1;
                }
                else if (min(ns0, ns1) == f2)
                {
                    p2 = np;
                    s0 = ns0, s1 = ns1;
                }
            }
        }
        if (max(f1, f2) == 0)
            cout << "Peace" << endl;
        else if (f1 > f2)
            cout << p[p1] << ' ' << f1 * 2 << endl;
        else
            cout << p[p2] << ' ' << f2 * 2 << endl;
        cout<<"===\n";
    }
    return 0;
}
