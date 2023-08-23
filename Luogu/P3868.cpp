#include<iostream>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y){
    if(!b) {x = 1, y = 0; return a;}
    long long d = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
long long quickmul(long long a, long long b, long long mod){
    a = (a % mod + mod) % mod, b = (b % mod + mod) % mod;
    return ((a * b - (long long)((long double)a / mod * b + 1e-6) * mod) % mod + mod) % mod;
}
long long a[15], b[15], n;
long long chinaleft(){
    long long M = 1, x, y, ans = 0;
    for(long long i = 1; i <= n; i ++) M = M * b[i];
    for(long long i = 1; i <= n; i ++){
        long long m = M / b[i];
        exgcd(b[i], m, x, y);
        y = (y % b[i] + b[i]) % b[i];
        ans =(ans + quickmul(y, quickmul(m, (a[i] + M) % M, M), M) + M) % M;
    }
    if(ans < 0) ans += M;
    return ans;
}
main(){
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i ++) scanf("%lld", a+i);
    for(long long i = 1; i <= n; i ++) scanf("%lld", b+i);
    printf("%lld", chinaleft());
    return 0;
}
