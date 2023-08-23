#include <iostream>
#include<algorithm>
using namespace std;
const int N = 10000000;
int vis[N + 100];
const int M = 664580;
int prime[M + 100];
int main (){
	int n = 0;
	for (int i = 2; i <= N; i ++){
		if (! vis [i]){
			vis [i] = i;
			prime [++ n] = i;
		}
		for (int j = 1; i * prime [j] <= N && j <= n; j ++){
			vis [i * prime [j]] = prime [j];
			if (vis [i] == prime [j]){
				break;
			}
		}
	}
	int t;
	scanf ("%d", &t);
	while (t --){
		int x, y;
		scanf ("%d%d", &x, &y);
		if (x + 1 == y){
			printf ("-1\n");
			continue;
		}
		if (__gcd (x, y) > 1){
			printf ("0\n");
			continue;
		}
		int c = y - x;
		int ans = INT_MAX;
		while (c > 1){
			ans = min (ans, (x / vis [c] + 1) * vis [c] - x);
			c /= vis [c];
		} 
		printf ("%d\n", ans);
	} 
	return 0;
}