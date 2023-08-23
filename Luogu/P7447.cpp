#include <bits/c++config.h>
#include <ostream>
#include <istream>
#include<limits.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define ls (num << 1)
#define rs (num << 1|1)
const int inf = INT_MAX, maxn = 2e4 + 7,N=5e5+7,B = 16, K = 32 ;
long long ma[9][maxn << 1],tag[9][maxn << 1], sum[9][maxn << 1],lb[9], rb[9];
int mx[9][maxn << 1], mn[9][maxn << 1],a[N],i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
void pushup(int biglatexflag, int num)
{
	ma[biglatexflag][num] = ma[biglatexflag][ls] + ma[biglatexflag][rs];
	sum[biglatexflag][num] = sum[biglatexflag][ls] + sum[biglatexflag][rs];
	mx[biglatexflag][num] = max(mx[biglatexflag][ls], mx[biglatexflag][rs]);
	mn[biglatexflag][num] = min(mn[biglatexflag][ls], mn[biglatexflag][rs]);
	return;
}
void pushdown(int biglatexflag, int num)
{
	if (!tag[biglatexflag][num])
		return;
	tag[biglatexflag][ls] += tag[biglatexflag][num] * (ma[biglatexflag][ls] != 0), tag[biglatexflag][rs] += tag[biglatexflag][num] * (ma[biglatexflag][rs] != 0);
	if (ma[biglatexflag][ls])
		sum[biglatexflag][ls] -= tag[biglatexflag][num] * ma[biglatexflag][ls], mx[biglatexflag][ls] -= tag[biglatexflag][num], mn[biglatexflag][ls] -= tag[biglatexflag][num];
	if (ma[biglatexflag][rs])
		sum[biglatexflag][rs] -= tag[biglatexflag][num] * ma[biglatexflag][rs], mx[biglatexflag][rs] -= tag[biglatexflag][num], mn[biglatexflag][rs] -= tag[biglatexflag][num];
	tag[biglatexflag][num] = 0;
	return;
}
int getbiglatexflag(int x)
{
	int now = 1;
	while (x > rb[now])
		now++;
	return now;
}
void biglatexflag_pushdown(int biglatexflag, int le, int rig, long long &x)
{
	if (!x)
		return;
	rep(i, le, rig) if (a[i] >= lb[biglatexflag] && a[i] <= rb[biglatexflag]) a[i] -= x;
	x = 0;
	return;
}
void biglatexflag_pushup(int biglatexflag, int le, int rig, int num)
{
	ma[biglatexflag][num] = 0, sum[biglatexflag][num] = 0, mx[biglatexflag][num] = 0, mn[biglatexflag][num] = inf;
	rep(i, le, rig)
	{
		if (a[i] >= lb[biglatexflag] && a[i] <= rb[biglatexflag])
		{
			ma[biglatexflag][num]++;
			sum[biglatexflag][num] += a[i];
			mx[biglatexflag][num] = max(mx[biglatexflag][num], a[i]);
			mn[biglatexflag][num] = min(mn[biglatexflag][num], a[i]);
		}
	}
	return;
}
void insert(int biglatexflag, int num, int le, int rig, int p, int x)
{
	if (rig - le + 1 <= K)
	{
		biglatexflag_pushdown(biglatexflag, le, rig, tag[biglatexflag][num]);
		a[p] = x;
		biglatexflag_pushup(biglatexflag, le, rig, num);
		return;
	}
	int mid = (le + rig) >> 1;
	pushdown(biglatexflag, num);
	if (p <= mid)
		insert(biglatexflag, ls, le, mid, p, x);
	else
		insert(biglatexflag, rs, mid + 1, rig, p, x);
	pushup(biglatexflag, num);
	return;
}
void biglatexflag_upd(int biglatexflag, int le, int rig, int x)
{
	rep(i, le, rig) if (a[i] >= lb[biglatexflag] && a[i] <= rb[biglatexflag] && a[i] > x)
	{
		a[i] -= x;
		if (a[i] < lb[biglatexflag])
		{
			insert(getbiglatexflag(a[i]), 1, 1, n, i, a[i]);
		}
	}
	return;
}
void biglatexflag_qry(int biglatexflag, long long &ans, int &maxn, int &minn, int le, int rig, int l, int r)
{
	rep(i, max(le, l), min(rig, r))
	{
		if (a[i] >= lb[biglatexflag] && a[i] <= rb[biglatexflag])
		{
			ans += a[i], maxn = max(maxn, a[i]), minn = min(minn, a[i]);
		}
	}
	return;
}
void upd(int biglatexflag, int num, int le, int rig, int l, int r, int x)
{
	if (mx[biglatexflag][num] <= x)
		return; 
	if (rig - le + 1 <= K)
	{
		biglatexflag_pushdown(biglatexflag, le, rig, tag[biglatexflag][num]);
		l = max(l, le), r = min(r, rig);
		biglatexflag_upd(biglatexflag, l, r, x);
		biglatexflag_pushup(biglatexflag, le, rig, num);
		return;
	} 
	if (le >= l && rig <= r && mn[biglatexflag][num] - lb[biglatexflag] >= x)
	{
		sum[biglatexflag][num] -= x * ma[biglatexflag][num], mn[biglatexflag][num] -= x, mx[biglatexflag][num] -= x; 
		tag[biglatexflag][num] += x;
		return;
	}
	int mid = (le + rig) >> 1;
	pushdown(biglatexflag, num);
	if (l <= mid)
		upd(biglatexflag, ls, le, mid, l, r, x);
	if (r > mid)
		upd(biglatexflag, rs, mid + 1, rig, l, r, x);
	pushup(biglatexflag, num);
	return;
}
void qry(long long &ans, int &maxn, int &minn, int biglatexflag, int num, int le, int rig, int l, int r)
{
	if (le >= l && rig <= r)
	{
		ans += sum[biglatexflag][num], maxn = max(maxn, mx[biglatexflag][num]), minn = min(minn, mn[biglatexflag][num]);
		return;
	} 
	if (rig - le + 1 <= K)
	{ 
		biglatexflag_pushdown(biglatexflag, le, rig, tag[biglatexflag][num]);
		biglatexflag_qry(biglatexflag, ans, maxn, minn, le, rig, l, r);
		biglatexflag_pushup(biglatexflag, le, rig, num);
		return;
	}
	int mid = (le + rig) >> 1;
	pushdown(biglatexflag, num); 
	if (l <= mid)
		qry(ans, maxn, minn, biglatexflag, ls, le, mid, l, r);
	if (r > mid)
		qry(ans, maxn, minn, biglatexflag, rs, mid + 1, rig, l, r);
	pushup(biglatexflag, num);
	return;
}
inline int read()
{
	int x = 0, y = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
		y = (ch == '-') ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return x * y;
}
void fwrite(int x)
{
	if (x > 9)
		fwrite(x / 10);
	putchar(x % 10 + '0');
	return;
}
void llfwrite(long long x)
{
	if (x > 9)
		llfwrite(x / 10);
	putchar(x % 10 + '0');
	return;
}
int main()
{
	rep(j, 1, 8) rep(i, 0, maxn * 2 - 2) mn[j][i] = inf, mx[j][i] = 0;
	n = read(), q = read();
	rep(i, 1, 8) lb[i] = rb[i - 1] + 1, rb[i] = lb[i] * B - 1;
	rep(i, 1, n) a[i] = x = read(), insert(getbiglatexflag(x), 1, 1, n, i, x);
	int op = 0, l = 0, r = 0, x = 0, lastans = 0, maxn = 0, minn = 0;
	long long ans = 0;
	while (q--)
	{
		op = read(), l = read() ^ lastans, r = read() ^ lastans;
		if (op == 1)
		{
			x = read() ^ lastans;
			rep(i, 1, 8) if (rb[i] >= x) upd(i, 1, 1, n, l, r, x);
		}
		else
		{
			ans = 0, maxn = 0, minn = inf;
			rep(i, 1, 8) qry(ans, maxn, minn, i, 1, 1, n, l, r);
			llfwrite(ans), putchar(' '), fwrite(minn), putchar(' '), fwrite(maxn), putchar('\n');
			lastans = ans % 1048576;
		}
	}
}
