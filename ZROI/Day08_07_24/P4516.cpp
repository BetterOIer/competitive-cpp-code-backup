#include <cctype>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>

template <typename T> inline void read(T& t) {
    int f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
template <typename T> inline bool chkMin(T& x, const T& y) { return y < x ? (x = y, true) : false; }
template <typename T> inline bool chkMax(T& x, const T& y) { return x < y ? (x = y, true) : false; }
#ifdef WIN32
#define LLIO "%I64d"
#else
#define LLIO "%lld"
#endif	// WIN32 long long
#define rep(I, A, B) for (int I = (A); I <= (B); ++I)
#define dwn(I, A, B) for (int I = (A); I >= (B); --I)
#define erp(I, X) for (int I = head[X]; I; I = next[I])

const int maxn = 1e5 + 7;
const long long mod = 1e9 + 7;
std::vector<int> G[maxn];
int dp[maxn][107][2][2], tmp[107][2][2];
int size[maxn];
int n, K;

inline int add(int x, long long y) {
    if (y >= mod) y %= mod;
    for (x += y; x >= mod; x -= mod);
    return x;
}
inline void ae(int x, int y) {
    G[x].push_back(y);
    G[y].push_back(x);
}
void dfs(int x, int fa) {
    size[x] = dp[x][0][0][0] = dp[x][1][1][0] = 1;
    for (unsigned e = 0; e < G[x].size(); ++e) {
        int v = G[x][e];
        if (v != fa) {
            dfs(v, x);
            rep(i, 0, std::min(size[x], K)) {
                tmp[i][0][0] = dp[x][i][0][0]; dp[x][i][0][0] = 0;
                tmp[i][0][1] = dp[x][i][0][1]; dp[x][i][0][1] = 0;
                tmp[i][1][0] = dp[x][i][1][0]; dp[x][i][1][0] = 0;
                tmp[i][1][1] = dp[x][i][1][1]; dp[x][i][1][1] = 0;
            }
            rep(i, 0, std::min(size[x], K))
                rep(j, 0, std::min(size[v], K - i)) {
                    dp[x][i + j][0][0] = add(dp[x][i + j][0][0], 1ll * tmp[i][0][0] * dp[v][j][0][1]);

                    dp[x][i + j][0][1] = add(dp[x][i + j][0][1], 1ll * tmp[i][0][1] * (dp[v][j][0][1] + dp[v][j][1][1]));
                    dp[x][i + j][0][1] = add(dp[x][i + j][0][1], 1ll * tmp[i][0][0] * dp[v][j][1][1]);

                    dp[x][i + j][1][0] = add(dp[x][i + j][1][0], 1ll * tmp[i][1][0] * (dp[v][j][0][0] + dp[v][j][0][1]));

                    dp[x][i + j][1][1] = add(dp[x][i + j][1][1], 1ll * tmp[i][1][0] * (dp[v][j][1][0] + dp[v][j][1][1]));
                    dp[x][i + j][1][1] = add(dp[x][i + j][1][1], 1ll * tmp[i][1][1] * (1ll * dp[v][j][0][0] + dp[v][j][0][1] + 1ll * dp[v][j][1][0] + dp[v][j][1][1]));
                }
                size[x] += size[v];
        }
    }
}

int main() {
    read(n); read(K);
    rep(i, 1, n - 1) {
        int x, y;
        read(x); read(y); ae(x, y);
    }
    dfs(1, 0);
    printf("%d\n", (int)((dp[1][K][0][1] + dp[1][K][1][1]) % mod));
    return 0;
}

