#include <cstdio>
#include<iostream>
using namespace std;
const int N = 20;
int n, s[N], p[N], l[N];
int exgcd(int a, int b, int &x, int &y){
    if (!b){x = 1, y = 0;return a;}
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
bool check(int m){
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j){
            int a = p[i] - p[j], b = m, c = s[j] - s[i], x, y;
            int d = exgcd(a, b, x, y);
            if (c % d) continue;
            a /= d, b /= d, c /= d;
            if (b < 0) b = -b;
            x = (x * c % b + b) % b;
            if (x <= l[i] && x <= l[j]) return 0;
        }
    return 1;
}
int main(){
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; ++i) scanf("%d%d%d", &s[i], &p[i], &l[i]), mx = max(mx, s[i]);
    for (int i = mx;; ++i) if (check(i)) return printf("%d\n", i), 0;
    return 0;
}

