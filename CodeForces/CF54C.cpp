#include <bits/stdc++.h>
#define Maxn 1005
#define Rep(i, l, r) for(long long i = l; i <= r; ++ i)
#define rep(i, l, r) for(long long i = l; i < r; ++ i)
#define Lep(i, l, r) for(long long i = l; i >= r; -- i)
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
double a[Maxn], f[Maxn];
long long p[Maxn];
long long calc(long long x) {
    if(x == 0) return 0;
    p[0] = 1; Rep(i, 1, 18) p[i] = p[i - 1] * 10; long long xx = x; 
    std :: vector <long long> g; while(x) g.push_back(x % 10), x /= 10;
    long long l = g.size() - 1; long long ans = 0;
    rep(i, 0, l) ans += p[i]; if(g[l] == 1) ans += xx - p[l] + 1; 
    else ans += p[l]; return ans;
}

double solve(long long x, long long y) {
    return (calc(x) - calc(y - 1)) * 1.0 / (x - y + 1);
}

int main() {
    long long n = read(), m, l, r; 
    Rep(i, 1, n) l = read(), r = read(), a[i] = solve(r, l);
    m = ceil(read() * n * 1.0 / 100); f[0] = 1;
    Rep(i, 1, n) Lep(j, n, 0) f[j] = f[j] * (1 - a[i]) + (j > 0) * f[j - 1] * a[i];
    double ans = 0; Rep(i, m, n) ans += f[i]; printf("%.9g", ans);
}
