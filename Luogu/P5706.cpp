#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, nb;
	float t, x;
	cin >> t >> n;
	x = t / n;
	nb = 2 * n;
	printf("%.3f\n%d", x, nb);

	return 0;
}
