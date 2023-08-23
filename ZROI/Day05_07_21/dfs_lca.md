DFS 序求$LCA$无论是从时间常数，空间常数还是好写程度方面均吊打欧拉序。

定义
DFS 序表示对一棵树进行深度优先搜索得到的 结点序列，而 时间戳 DFN 表示每个结点在$DFS$序中的位置。这两个概念需要着重区分。

算法介绍
考虑树上的两个结点 
,
u,v 及其最近公共祖先 
d，我们不得不使用欧拉序求$LCA$的原因是在欧拉序中，
d 在 
,
u,v 之间出现过，但在$DFS$序中，
d 并没有在 
,
u,v 之间出现过。对于$DFS$序而言，祖先一定出现在后代之前（性质）。

不妨设 
u 的 DFN 小于 
v 的 DFN（假设）。

当 
u 不是 
v 的祖先 时（情况 1），DFS 的顺序为从 
d 下降到 
u，再回到 
d，再往下降到 
v。

根据性质，任何 
d 以及 
d 的祖先均不会出现在 
∼
u∼v 的$DFS$序中。

考察 
d 在 
v 方向上的第一个结点 
′
v 
′
 ，即设 
′
v 
′
  为 
d 的 / 子树包含 
v 的 / 儿子。根据$DFS$的顺序，显然 
′
v 
′
  在 
∼
u∼v 的$DFS$序之间。

这意味着什么？我们只需要求在 
u 的$DFS$序和 
v 的$DFS$序之间深度最小的任意一个结点，那么 它的父亲 即为 
,
u,v 的 LCA。

这样做的正确性依赖于在$DFS$序 
u 到 
v 之间，
d 以及 
d 的祖先必然不会存在，且必然存在 
d 的儿子。

,
u,v 成祖先后代关系（情况 2）是容易判断的，但这不优美，不能体现出$DFS$求$LCA$的优势：简洁。为了判断还要记录每个结点的子树大小，但我们自然希望求$LCA$的方法越简单越快越好。

根据假设，此时 
u 一定是 
v 的祖先。因此考虑令查询区间从 
[
,
]
[dfn 
u
​
 ,dfn 
v
​
 ] 变成 
[
+
1
,
]
[dfn 
u
​
 +1,dfn 
v
​
 ]。

对于情况 1，
u 显然一定不等于 
′
v 
′
 ，所以情况 2 对于算法进行的修改仍然适用于情况 1。

综上，若 
≠
u 

​
 =v，则 
,
u,v 之间的$LCA$等于在$DFS$序中，位置在 
+
1
dfn 
u
​
 +1 到 
dfn 
v
​
  之间的深度最小的结点的父亲。若 
=
u=v，则它们的$LCA$就等于 
u，这是唯一需要特判的情况。

预处理$ST$表的复杂度仍为$O(nlogn)$，但常数减半。以下是模板题 P3379 的代码。

```cpp
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 5;
int n, m, R, dn, dfn[N], mi[19][N];
vector<int> e[N];
int get(int x, int y) {return dfn[x] < dfn[y] ? x : y;}
void dfs(int id, int f) {
  mi[0][dfn[id] = ++dn] = f;
  for(int it : e[id]) if(it != f) dfs(it, id); 
}
int lca(int u, int v) {
  if(u == v) return u;
  if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
  int d = __lg(v - u++);
  return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}
int main() {
  scanf("%d %d %d", &n, &m, &R);
  for(int i = 2, u, v; i <= n; i++) {
    scanf("%d %d", &u, &v);
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs(R, 0);
  for(int i = 1; i <= __lg(n); i++)
  for(int j = 1; j + (1 << i) - 1 <= n; j++)
    mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  for(int i = 1, u, v; i <= m; i++) scanf("%d %d", &u, &v), printf("%d\n", lca(u, v));
  return 0;
}
```
和各种$LCA$算法的对比
对比$DFS$序和欧拉序，不仅预处理的时间常数砍半（欧拉序$LCA$的瓶颈恰好在于预处理，DFS 是线性），空间常数也砍半（核心优势），而且还更好写（对于一些题目就不需要再同时求欧拉序和$DFS$序了），也不需要担心忘记开两倍空间，可以说前者从各个方面吊打后者。

对比$DFS$序和倍增，前者单次查询复杂度更优。

对于$DFS$序和四毛子，前者更好写，且单次查询常数更小（其实差不多）。

对于$DFS$序和树剖，前者更好写，且单次查询复杂度更优（但树剖常数较小）。

将$DFS$序求$LCA$发扬光大，让欧拉序求$LCA$成为时代的眼泪！