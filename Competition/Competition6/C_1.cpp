#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
LL f[100005][3];
int main(){
    int n;
    scanf ("%d", &n);
    for (int i= 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        f[i][0] = max(f[i - 1][0], max(f[i - 1][1], f[i - 1][2]));
        f[i][1] = f[i - 1][0] + x;
        f[i][2] = f[i - 1][1] + x;
    }
    printf("%lld\n", max(f[n][0], max(f[n][1], f[n][2])));
    return 0;
}