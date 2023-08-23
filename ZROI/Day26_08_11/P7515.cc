#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? (i <= (b)) : (i >= (b)); i += (c))
#define pub push_back
#define pob pop_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int T;
int n, m;
int b[305][305], a[305][305];
vector<pair<int, int> > egs[605];
bool inq[605];
int tms[605];
ll dis[605];

void solve() {
	scanf("%d%d", &n, &m);
	cont(i, n - 1) cont(j, m - 1) scanf("%d", b[i] + j);
	memset(a, 0, sizeof(a));
	range(i, n, 1, -1) range(j, m, 1, -1) a[i][j] = b[i][j] - a[i + 1][j] - a[i + 1][j + 1] - a[i][j + 1];
    cout<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<a[i][j]<<" \n"[j==m];
        }
    }
    cout<<"===\n";
	cont(i, n + m) egs[i].clear();
	cont(i, n) cont(j, m) {
		int mx = 1000000 - a[i][j], mn = -a[i][j];
		if (!((i + j) & 1)) egs[j + n].pub(mak(i, mx)), egs[i].pub(mak(j + n, -mn));
		else egs[j + n].pub(mak(i, -mn)), egs[i].pub(mak(j + n, mx));
	}
	deque<int> q;
	memset(inq, 0, sizeof(inq));
	memset(tms, 0, sizeof(tms));
	memset(dis, Inf, sizeof(dis));
	dis[1] = 0;
	q.pub(1);
	while (SZ(q)) {
		int now = q.front(); q.pop_front();
		++tms[now]; inq[now] = 0;
		if (tms[now] > n + m) {
			puts("NO");
			return;
		}
		loop(i, SZ(egs[now])) {
			int to = egs[now][i].first, siz = egs[now][i].second;
			if (dis[to] > dis[now] + siz) {
				dis[to] = dis[now] + siz;
				if (!inq[to]) {
					if (SZ(q) && dis[to] < dis[q[0]]) q.push_front(to);
					else q.pub(to);
					inq[to] = 1;
				}
			}
		}
	}
    for(int i = 1;i<=n+m;i++)cout<<dis[i]<<" \n"[i==n+m];
	cont(i, n) cont(j, m) {
		if ((i + j) & 1) a[i][j] -= dis[i];
		else a[i][j] += dis[i];
		if ((i + j) & 1) a[i][j] += dis[j + n];
		else a[i][j] -= dis[j + n];
	}
	puts("YES");
	cont(i, n) cont(j, m) printf("%d%c", a[i][j], " \n"[j == m]);
}

int main() {
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
