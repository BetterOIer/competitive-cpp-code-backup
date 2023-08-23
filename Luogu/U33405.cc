#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int a[2002];
int n, R;
inline int read()
{
    int v = 0, c = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            c = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        v = v * 10 + ch - 48;
        ch = getchar();
    }
    return v * c;
}
int w[2002];
int L;
inline bool check(int mid)
{
    int res = 0;
    int now = mid;
    multiset<int> s;
    multiset<int>::iterator it;
    s.clear();
    for (int i = 1; i <= n; ++i)
        s.insert(w[i]);
    while (!s.empty())
    {
        while (!s.empty() && now >= *s.begin())
        {
            it = s.upper_bound(now);
            it--;
            now -= *it;
            s.erase(it);
        }
        now = mid;
        res++;
        if (res > R)
            break;
    }
    return res <= R;
}
int main()
{
    n = read(), R = read();
    int r = 0;
    for (int i = 1; i <= n; ++i)
        w[i] = read(), r += w[i];
    sort(w + 1, w + n + 1);
    L = w[n];
    int l = L;
    int now = 0, ans;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1, now = mid;
        else
            l = mid + 1;
    }
    ans = now;
    for (int i = now - L; i <= now; ++i)
        if (check(i))
        {
            cout << i << endl;
            return 0;
        }
    cout << ans;
    return 0;
}