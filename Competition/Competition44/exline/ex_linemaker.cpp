#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
inline long long read()
{
	long long x = 0, f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (; isdigit(c); c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}
long long t, n, cnt, cntl;
long long x[N], y[N];
long long a[N], b[N];
long long be[105][105];
int main()
{
	freopen(".in","r",stdin);
	t = read();
	while (t--)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		bool flag = false;
		n = read();
		if (n > 50)
		{
			for (long long i = 1; i <= n; i++)
			{
				a[i] = read(), b[i] = read();
				x[a[i]]++, y[b[i]]++;
			}
			sort(a + 1, a + 1 + n);
			sort(b + 1, b + 1 + n);
			cnt = 0, cntl = 0;
			for (long long i = 1; i <= n; i++)
			{
				if (a[i] != a[i + 1])
				{
					cnt += x[a[i]];
					if (cnt == n / 2)
					{
						puts("2");
						flag = true;
						break;
					}
				}
				if (b[i] != b[i + 1])
				{
					cntl += y[b[i]];
					if (cntl == n / 2)
					{
						puts("2");
						flag = true;
						break;
					}
				}
			}
			if (flag)
				continue;
			puts("3");
		}
		else
		{
			memset(be, 0, sizeof(be));
			for (long long i = 1; i <= n; i++)
			{
				a[i] = read(), b[i] = read();
				be[a[i]][b[i]] = 1;
				x[a[i]]++, y[b[i]]++;
			}
			sort(a + 1, a + 1 + n);
			sort(b + 1, b + 1 + n);
			cnt = 0, cntl = 0;
			for (long long i = 1; i <= n; i++)
			{
				if (a[i] != a[i + 1])
				{
					cnt += x[a[i]];
					if (cnt == n / 2)
					{
						puts("2");
						flag = true;
						break;
					}
				}
				if (b[i] != b[i + 1])
				{
					cntl += y[b[i]];
					if (cntl == n / 2)
					{
						puts("2");
						flag = true;
						break;
					}
				}
			}
			if (flag)
				continue;
			for (long long i = 1; i <= n; i++)
			{
				for (long long j = 1; j <= n; j++)
				{
					be[i][j] = be[i - 1][j] + be[i][j] + be[i][j - 1] - be[i - 1][j - 1];
				}
			}
			cnt = 0, cntl = 0;
			for (long long i = 1; i <= n; i++)
			{
				cnt += x[i];
				for (long long j = 1; j <= n; j++)
				{
					if (cnt - be[i][j] == n / 2)
					{
						puts("3");
						flag = true;
						break;
					}
				}
				if (flag)
					break;
				cntl += y[i];
				for (long long j = 1; j <= n; j++)
				{
					if (cntl - be[j][i] == n / 2)
					{
						puts("3");
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				continue;
			puts("4");
		}
	}
	return 0;
}
