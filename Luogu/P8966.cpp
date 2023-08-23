#include <bits/stdc++.h>

typedef long long LL;

const int N = 1010, M = N * 2;

int n;
struct Tree
{
	int l, r;
	void init(int _l, int _r)
	{
		l = _l, r = _r;
	}
}tr[N];
LL c[N], sz[N];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i ++ ) tr[i].init(0, 0);

	for (int i = 2; i <= n; i ++ )
	{
		int p;
		scanf("%d", &p);
		if (tr[p].l) tr[p].r = i;
		else tr[p].l = i;
	}
	for (int i = 1; i <= n; i ++ ) scanf("%lld", &c[i]);

	auto calc = [&](auto calc, int x) -> LL
	{
		LL s = c[x];
		if (tr[x].l) s += calc(calc, tr[x].l);
		if (tr[x].r) s += calc(calc, tr[x].r);
		return sz[x] = s; 
	};
	calc(calc, 1);

	auto dfs = [&](auto dfs, int x, int v) -> LL
	{
		LL left = 0, right = 0;
		if (tr[x].l) left = dfs(dfs, tr[x].l, v);
		if (tr[x].r) right = dfs(dfs, tr[x].r, v);
		if (left) return left + std::min(left, sz[tr[x].r]);
		if (right) return right + std::min(sz[tr[x].l], right);
		if (x == v) return sz[x];
		return 0;
	};

	for (int i = 1; i <= n; i ++ ) printf("%lld ", dfs(dfs, 1, i));
	return 0;
}
