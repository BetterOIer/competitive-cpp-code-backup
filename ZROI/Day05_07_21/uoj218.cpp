/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
/* #include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,ty,last,idx,rt_idx;//注意n,m, ty强制在线
struct node{
    int lc;
    int rc;
    int val;
    //int tag;
}tr[10000005];
int root[1000005];
void pushup(int pos){
    tr[pos].val=tr[tr[pos].lc].val+tr[tr[pos].rc].val;
}
void pushdown(int pos){

}
void build(int &pos,int l,int r){
    pos=++idx;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(tr[pos].lc,l,mid);build(tr[pos].rc,mid+1,r);
}
void update(int pre,int &pos,int l,int r,int x, int y,int val){//修改直接是覆盖操作
    pos=++idx;tr[pos]=tr[pre];
    pushdown(pos);
    if(x<=l&&r<=y){
        tr[pos].val=val*(r-l+1);
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=x) update(tr[pre].lc,tr[pos].lc,l,mid,x,y,val);
    if(mid<y) update(tr[pre].rc,tr[pos].rc,mid+1,r,x,y,val);
    pushup(pos);
}
int query(int pos,int l, int r, int x,int y){
    pushdown(pos);
    if(x<=l&&r<=y){
        return tr[pos].val;
    }
    int mid = (l+r)>>1,ans=0;
    if(mid>=x) ans+=query(tr[pos].lc,l,mid,x,y);
    if(mid<y) ans+=query(tr[pos].rc,mid+1,r,x,y);
    return ans;
}
int main(){
    n=read(),m=read(),ty=read();
    build(root[0],1,n);
    for(int i = 1,opt,l,r,x;i<=m;i++){
        opt=read();
        if(opt==1){
            l=(read()+last*ty)%(n+1),r=(read()+last*ty)%(n+1);
            if(l>r)swap(l,r);
        }else if(opt==2){
            l=(read()+last*ty)%(n+1);
            
            update()
        }else{
            l=(read()+last*ty)%(n+1),r=(read()+last*ty)%(n+1),x=read();
            if(l>r)swap(l,r);
            ++rt_idx;
            update(root[rt_idx-1],root[rt_idx],1,n,l,r,x);
        }
    }
    return 0;
}












 */





































































#include <bits/stdc++.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
	int ch = 0, f = 0; x = 0;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
	if(f) x = -x;
}
const int N = 500005;
int q[N], rt[N], n, m, ty, tim, op, l, r, x; 
#define fi first
#define se second
inline pair<int, int> chkmax(pair<int, int> A, pair<int, int> B){
	return A.fi > B.fi ? A : B;
}
#define mid ((l + r) >> 1)
	
namespace Seg{
	#define lson (u << 1)
	#define rson (u << 1 | 1)
	int s[N<<2], tag[N<<2];
	inline void pushdown(int u, int l, int r){
		if(!tag[u]) return;
		s[lson] = (mid - l + 1) * tag[u], tag[lson] = tag[u];
		s[rson] = (r - mid) * tag[u], tag[rson] = tag[u], tag[u] = 0;
	}
	inline void change(int u, int l, int r, int L, int R, int x){
		if(l >= L && r <= R) return (void) (tag[u] = x, s[u] = (r - l + 1) * x);
		pushdown(u, l, r);
		if(L <= mid) change(lson, l, mid, L, R, x);
		if(mid < R) change(rson, mid + 1, r, L, R, x);
		s[u] = s[lson] + s[rson];
	}
	inline int query(int u, int l, int r, int L, int R){
		if(l >= L && r <= R) return s[u];
		int res = 0; pushdown(u, l, r);
		if(L <= mid) res += query(lson, l, mid, L, R);
		if(mid < R) res += query(rson, mid + 1, r, L, R);
		return res;
	}

}
namespace Tim{
	int lc[N*25], rc[N*25], size; pair<int, int> tag[N*25];
	inline int copynode(int x){
		return lc[++size] = lc[x], rc[size] = rc[x], tag[size] = tag[x], size;
	}
	inline void ins(int &u, int pr, int l, int r, int L, int R, pair<int, int> x){
		u = copynode(pr);
		if(l >= L && r <= R) return (void) (tag[u] = x);
		if(L <= mid) ins(lc[u], lc[pr], l, mid, L, R, x);
		if(mid < R) ins(rc[u], rc[pr], mid + 1, r, L, R, x);
	}
	inline pair<int, int> query(int u, int l, int r, int pos){
		if(l == r) return tag[u];
		if(pos <= mid) return chkmax(tag[u], query(lc[u], l, mid, pos));
		else return chkmax(tag[u], query(rc[u], mid + 1, r, pos));
	}
}	
int main(){
	read(n), read(m), read(ty); int lastans = 0;
	while(m--){
		read(op);
		if(op == 1){
			read(l), read(r);
			l = (l + lastans * ty) % n + 1, r = (r + lastans * ty) % n + 1;
			if(l > r) swap(l, r);
			printf("%d\n", lastans = Seg::query(1, 1, n, l, r));
		}
		if(op == 2){
			read(l), l = (l + lastans * ty) % n + 1;
			pair<int, int> now = Tim::query(rt[tim], 1, n, l);
			if(!now.se) continue;
			pair<int, int> tmp = Tim::query(rt[now.se-1], 1, n, l);
			Seg::change(1, 1, n, l, l, q[tmp.se]);
			++tim;
			Tim::ins(rt[tim], rt[tim-1], 1, n, l, l, make_pair(tim, tmp.se));
		}
		if(op == 3){
			read(l), read(r), read(x);
			l = (l + lastans * ty) % n + 1, r = (r + lastans * ty) % n + 1;
			if(l > r) swap(l, r);
			q[++tim] = x;
			Seg::change(1, 1, n, l, r, q[tim]);
			Tim::ins(rt[tim], rt[tim-1], 1, n, l, r, make_pair(tim, tim));
		}
	}
	return 0;
}