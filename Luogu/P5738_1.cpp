#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	float sum = -1;
	while (n--) {
		float t = 0, mina = 100, maxa = -1,ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> t;
			ans += t;
			mina = min(t, mina), maxa = max(t, maxa);
		}
		ans -= mina + maxa;
		ans /= m - 2.0;
		sum = max(ans, sum);
	}
	printf("%.2f", sum);
	return 0;
} 