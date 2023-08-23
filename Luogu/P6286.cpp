#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
string s[1001];
int sum, vis[1001], VIS[1001], ans[20010], ans2[20010],n, tot, fla, a[1001], in[1001], head[200010], ANS[20010];
struct node
{
    int to, net;
} e[200010];
void add(int u, int v)
{
    e[++tot].to = v;
    e[tot].net = head[u];
    head[u] = tot;
}
int tuopu()
{
    queue<int> q;
    for (int i = 0; i <= 25; i++)
    {
        if (!in[i] && vis[i])
            q.push(i);
    }
    if (!q.size())
        return -1;
    while (!q.empty())
    {
        bool flag = false;
        int x = q.front();
        q.pop();
        if (VIS[x])
            return -1;
        VIS[x] = 1;
        ans[++sum] = x;
        ans2[sum] = x;
        for (int i = head[x]; i; i = e[i].net)
        {
            int v = e[i].to;
            if (--in[v] == 0)
            {
                flag = true;
                q.push(v);
            }
        }
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int k = 0, kk = 0;
        while (k < s[a[i]].size() && kk < s[a[i + 1]].size())
        {
            if (s[a[i]][k] != s[a[i + 1]][kk])
            {
                add(s[a[i]][k] - 'a', s[a[i + 1]][kk] - 'a');
                if (!vis[s[a[i]][k] - 'a'])
                    fla++, vis[s[a[i]][k] - 'a'] = 1;
                if (!vis[s[a[i + 1]][kk] - 'a'])
                    fla++, vis[s[a[i + 1]][kk] - 'a'] = 1;
                in[s[a[i + 1]][kk] - 'a']++;
                break;
            }
            k++;
            kk++;
        }
        if (fla == 0 && s[a[i]].size() > s[a[i + 1]].size())
        {
            puts("NE");
            return 0;
        }
    }
    if (fla == 0)
    {
        puts("DA");
        for (int i = 0; i <= 25; i++)
            cout << char(i + 'a');
        return 0;
    }
    int t = tuopu();
    if (t == -1)
    {
        puts("NE");
        return 0;
    }
    sort(ans + 1, ans + 1 + sum);
    for (int i = 1; i <= sum; i++)
    {
        ANS[ans2[i]] = ans[i];
    }
    for (int i = 0; i <= 25; i++)
    {
        if (vis[i] && !VIS[i])
        {
            puts("NE");
            return 0;
        }
        if (!VIS[i])
            ANS[i] = i;
    }
    puts("DA");
    for (int i = 0; i <= 25; i++)
    {
        cout << char(ANS[i] + 'a');
    }
    return 0;
}