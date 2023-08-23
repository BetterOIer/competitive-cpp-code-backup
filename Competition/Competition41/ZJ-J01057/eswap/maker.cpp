#include <cstdio>
#include <queue>
std::priority_queue<int> q; 
int x; long long ans = 0;
int main() {
    freopen("eswap10.in","r",stdin);
    freopen("eswap10.out","w",stdout);
	while (scanf("%d", &x) != EOF) {
		q.push(-x);
		int t = q.top() + x;
		if (t > 0) {
			ans += t;
			q.pop();
			q.push(-x);
		}
	}
	printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
}
