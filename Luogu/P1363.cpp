#include<iostream>
#include<cstring>
using namespace std;
int dt[1501][1501][3];
bool a[1501][1501];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int m,n,stx,sty;
bool flag=false;
void dfs(int x, int y, int lx, int ly) {
	if(flag) return;
	if(dt[x][y][0] && (dt[x][y][1]!=lx || dt[x][y][2]!=ly)) {
		flag = 1;
		return;
	}
	dt[x][y][1] = lx, dt[x][y][2] = ly, dt[x][y][0] = 1;
	for(int i=0; i<4; ++i) {
		int xx = (x + dx[i] + n) % n, yy = (y + dy[i] + m) % m;
		int lxx = lx + dx[i], lyy = ly + dy[i];
		if(!a[xx][yy]) {
			if(dt[xx][yy][1]!=lxx || dt[xx][yy][2]!=lyy || !dt[xx][yy][0])
				dfs(xx, yy, lxx, lyy);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	while(cin >> n >> m) {
		flag = 0;
		memset(a, 0, sizeof(a));
		memset(dt, 0, sizeof(dt));
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j) {
                char c;
				cin >> c;
				if(c == '#') a[i][j] = 1;
				if(c == 'S') stx = i, sty = j;
			}
		dfs(stx, sty, stx, sty);
		if(flag) puts("Yes");
		else puts("No");
	}
}