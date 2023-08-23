#include <cstdio>
#define int ll
typedef long long ll;
const int mod = 998244353;
int cnt = 0, h[1000005], leadinto[2000005], everyone[2000005], f[1000005], ansorsumorcnt[1000005], fuck[1000005];
inline int read(){
    register int x = 0, f = 1;
    register char s = getchar();
    while (s > '9' || s < '0'){
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9')
{
        x = x * 10 + s - '0';
        s = getchar();
    }
    return x * f;
}
inline void add(int x, int y){
    leadinto[++cnt] = y;
    everyone[cnt] = h[x];
    h[x] = cnt;
}
signed main(){
    int id = read(), n = read(), m = read();
    for (register int i = 1; i <= m; ++i){
        int x = read(), y = read();
        add(x, y);
        ++fuck[x];
    }
    for (register int x = 1; x <= n; ++x){
        f[x] = fuck[x] + 1;
        for (register int i = h[x]; i; i = everyone[i]){
            int y = leadinto[i];
            f[x] = ((f[x] + (ansorsumorcnt[x - 1] - ansorsumorcnt[y - 1]) % mod) % mod + mod);
        }
        ansorsumorcnt[x] = (ansorsumorcnt[x - 1] + f[x]) % mod;
    }
    printf("%lld\n", ansorsumorcnt[n]);
    return 0;
}