#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;
struct Edge{
	int from, to, w;
} p[200019];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n, m, L, R, cnt, head[200019];

void add_edge(int x, int y, int W){
	cnt++;
	p[cnt].from = head[x];
	head[x] = cnt;
	p[cnt].to = y;
	p[cnt].w = W;
}
bool work(int mid){
	queue<int> q;
	int col[20009] = {0};
	for (int i = 1; i <= n; i++)
		if (!col[i]){
			q.push(i);
			col[i] = 1;
			while (!q.empty()){
				int x = q.front();q.pop();
				for (int i = head[x]; i; i = p[i].from)
					if (p[i].w >= mid){
						if (!col[p[i].to]){
							q.push(p[i].to);
							if (col[x] == 1) col[p[i].to] = 2;
							else col[p[i].to] = 1;
						}
						else if (col[p[i].to] == col[x]) return false;
					}
			}
		}
	return true;
}
int main(){
	n = read(), m = read();
	for (int i = 1; i <= m; i++){
		int x = read(), y = read(), w = read();
		R = max(R, w);
		add_edge(x, y, w),add_edge(y, x, w);
	}
	R++;
	while (R > L + 1){
		int mid = (L + R) >> 1;
		if (work(mid)) R = mid;
		else L = mid;
	}
	printf("%d", L);
	return 0;
}
