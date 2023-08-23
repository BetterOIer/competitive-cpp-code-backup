#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2000005, INF = 0x3f3f3f3f;
int n, m, base[N],c;

struct node {
	int l=0, r=0, sum=0, lx=0, rx=0, ans=0,lm=0,rm=0;
} tree[N*4];

void  pushup(int p){
	tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
    if(tree[p<<1].lx>=tree[p<<1].sum + tree[p<<1|1].lx){
        tree[p].lx = tree[p<<1].lx;
        tree[p].lm=tree[p<<1].lm;
    }else{
        tree[p].lx = tree[p<<1].sum + tree[p<<1|1].lx;
        tree[p].lm=tree[p<<1].r-tree[p<<1].l+1+tree[p<<1|1].lm;
    }
    if(tree[p<<1|1].rx>=tree[p<<1|1].sum + tree[p<<1].rx){
        tree[p].rx = tree[p<<1|1].rx;
        tree[p].rm = tree[p<<1|1].rm;
    }else{
        tree[p].rx = tree[p<<1|1].sum + tree[p<<1].rx;
        tree[p].rm=tree[p<<1|1].r-tree[p<<1|1].l+1+tree[p<<1].rm;
    }
    
	/* tree[p].lx = max(tree[p<<1].lx, tree[p<<1].sum + tree[p<<1|1].lx); */
	/* tree[p].rx = max(tree[p<<1|1].rx, tree[p<<1].rx + tree[p<<1|1].sum); */
	tree[p].ans = max(max(tree[p<<1].ans, tree[p<<1|1].ans), tree[p<<1].rx + tree[p<<1|1].lx);
}
void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (l == r) {
		tree[p].sum = tree[p].lx = tree[p].rx = tree[p].ans = base[l];
        tree[p].lm=tree[p].rm=1;
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
 
node ask(int p, int l, int r) {
	if (l <= tree[p].l && r >= tree[p].r) return tree[p];
	node a, b, ans;
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
    int kua=a.rx + b.lx;
    int kualen=a.rm + b.lm,lef=tree[p<<1].r-a.rm+1,ref=tree[p<<1|1].l+b.lm;
    //cout<<endl<</* lef<<"="<<tree[p<<1].r<<'-'<<a.rm<<"+1"<<endl<<ref<<"="<<tree[p<<1|1].l<<"+"<< */b.lm<<endl;
    while(kualen>c){
        if(base[lef]<base[ref]){
            kua-=base[lef];
            lef++;
        }
        else if(base[lef]>=base[ref]){
            kua-=base[ref];
            ref--;
        }
        kualen--;
    }
	ans.ans = max(max(a.ans, b.ans), kua);
    if(a.lx>=a.sum + b.lx){
        ans.lx=a.lx;
        ans.lm=a.lm;
    }else{
        ans.lx=a.sum + b.lx;
        ans.lm=tree[p<<1].r-tree[p<<1].l+1+b.lm;
    }
    if(b.rx>=b.sum + a.rx){
        ans.rx=b.rx;
        ans.rm=b.rm;
    }else{
        ans.rx=b.sum + a.rx;
        ans.rm=tree[p<<1|1].r-tree[p<<1|1].l+1+b.rm;
    }
	/* ans.lx = max(a.lx, a.sum + b.lx);
	ans.rx = max(b.rx, b.sum + a.rx); */
	if (l > mid){
        if(ans.lx<b.lx){
            ans.lx=b.lx;
            ans.lm=b.lm;
        }
        /* ans.lx = max(ans.lx, b.lx); */
    }
	if (r <= mid){
        if(ans.rx< a.rx){
            ans.rx=a.rx;
            ans.rm=a.rm;
        }
        /* ans.rx = max(ans.rx, a.rx); */
    }
    //cout<<endl<<ans.lm<<' '<<ans.rm<<endl;
	return ans;
}
 
int main() {
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) scanf("%d", &base[i]);
	build(1, 1, n);
    /* for(int i = 1;i<=4000;i++){
        cout<<tree[i].lm<<" "<<tree[i].rm<<endl;
    } */
	while (m--) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if (t == 2) {
			if (x > y) swap(x, y);
            int AN=ask(1, x, y).ans;
			cout <<(AN>0?AN:0)<< endl;
		}
		else change(1, x, y);
	}
	return 0;
}