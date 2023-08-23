//*** Le valent se lèvale, il faut tenter de valivalre ***
#include <iostream>
using namespace std;
inline void read(int &num){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	num=x*f;
}
inline void read(long long &num){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	num=x*f;
}
struct node{
	int l=0, r=0;
    long long size,c;
}tree[1004];
int n;
long long calc(int pos){
	long long size = tree[pos].c;
	if(tree[pos].l)size+=calc(tree[pos].l);
	if(tree[pos].r)size+=calc(tree[pos].r);
    return tree[pos].size=size;
}
long long dfs(int pos, int val){
	long long l_ans = 0, r_ans = 0;
	if(tree[pos].l) l_ans = dfs(tree[pos].l,val);
	if(tree[pos].r) r_ans = dfs(tree[pos].r,val);
	if(l_ans) return l_ans + min(l_ans,tree[tree[pos].r].size);
	if(r_ans) return r_ans + min(tree[tree[pos].l].size,r_ans);
	if(pos == val) return tree[pos].size;
	return 0LL;
}
int main(){
    read(n);
	for(int i = 2,fa;i<=n;i++){
		read(fa);
		if (tree[fa].l) tree[fa].r = i;
		else tree[fa].l = i;
	}
	for(int i = 1;i<=n;i++) read(tree[i].c);
    calc(1);
	for (int i = 1;i<=n;i++) printf("%lld ",dfs(1,i));
	return 0;
}