/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 我有故人抱剑去，斩尽春风未曾归。 --孤山不孤
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int fa[150004],n,m,ans;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int main(){
    n = read(), m = read();
	for (int i = 1; i <= n * 3; i++) { fa[i] = i; }
	for (; m; m--) {
		int opt = read(), u = read(), v = read();
		if (u > n || v > n) { ans++; continue; }
		if (opt == 1) {
			if (find(u + n) == find(v) || find(u) == find(v + n)) { ans++; }
			else {
				fa[find(u)] = find(v);
				fa[find(u + n)] = find(v + n);
				fa[find(u + n + n)] = find(v + n + n);
			}
		} else {
			if (find(u) == find(v) || find(u) == find(v + n)) { ans++; }
			else {
				fa[find(u + n)] = find(v);
				fa[find(u + n + n)] = find(v + n);
				fa[find(u)] = find(v + n + n);
			}
		}
	}
    printf("%d\n", ans);
	return 0;
}