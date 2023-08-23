 
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000006, INF = 0x3f3f3f3f;
int n, m, a[N];
struct T {
	int l, r, sum, lx, rx, ans;
} tree[N*4];
void  pushup(int p){
	tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
	tree[p].lx = max(tree[p<<1].lx, tree[p<<1].sum + tree[p<<1|1].lx);
	tree[p].rx = max(tree[p<<1|1].rx, tree[p<<1].rx + tree[p<<1|1].sum);
	tree[p].ans = max(max(tree[p<<1].ans, tree[p<<1|1].ans), tree[p<<1].rx + tree[p<<1|1].lx);
}
void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (l == r) {
		tree[p].sum = tree[p].lx = tree[p].rx = tree[p].ans = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
 
void change(int p, int x, int y) {
	if (tree[p].l == tree[p].r) {
		tree[p].sum = tree[p].lx = tree[p].rx = tree[p].ans = y;
		return;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (x <= mid) change(p << 1, x, y);
	else change(p << 1 | 1, x, y);
	pushup(p);
}
 
T ask(int p, int l, int r) {
	if (l <= tree[p].l && r >= tree[p].r) return tree[p];
	T a, b, ans;
	a.sum = a.lx = a.rx = a.ans = b.sum = b.lx = b.rx = b.ans = -INF;
	ans.sum = 0;
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (l <= mid) {
		a = ask(p << 1, l, r);
		ans.sum += a.sum;
	}
	if (r > mid) {
		b = ask(p << 1 | 1, l, r);
		ans.sum += b.sum;
	}
	ans.ans = max(max(a.ans, b.ans), a.rx + b.lx);
	ans.lx = max(a.lx, a.sum + b.lx);
	ans.rx = max(b.rx, b.sum + a.rx);
	if (l > mid) ans.lx = max(ans.lx, b.lx);
	if (r <= mid) ans.rx = max(ans.rx, a.rx);
	return ans;
}
 
int main() {
    int base;
	cin >> n >> m>>base;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	while (m--) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if (t == 2) {
			if (x > y) swap(x, y);
            int AN=ask(1, x, y).ans;
			cout << (AN<0?0:AN) << endl;
		}
		else change(1, x, y);
	}
	return 0;
}