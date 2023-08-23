/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
map <string, int> b, c;
string name[21], a[21][101];
int d[21];
int n;
int main () {
	n=read();
	for(int i = 1; i <= n; i++) {
		cin>>name[i];d[i]=read();
		if (c[name[i]] == 0) {
			c[name[i]] = i;
			for(int j = 1; j <= d[i]; j++) cin >> a[i][j], ++b[a[i][j]];
			for(int j = 1; j <= d[i]; j++) {
				if (b[a[i][j]] == 0) continue;
				string s = a[i][j];
				int t = s.size();
				for(int k = 1; k < t; k++) {
					s.erase(0, 1);
					if (b[s] != 0) b[s] = 0;
				}
			}
			int K = d[i];
			d[i] = 0;
			for(int j = 1; j <= K; j++) {
				if (b[a[i][j]] != 0) a[i][++d[i]] = a[i][j], b[a[i][j]] = 0;
			}
		}
		else {
			int T = d[c[name[i]]];
			d[c[name[i]]] += d[i];
			for(int j = 1; j <= T; j++) ++b[a[c[name[i]]][j]];
			for(int j = T + 1; j <= d[c[name[i]]]; j++) cin >> a[c[name[i]]][j], ++b[a[c[name[i]]][j]];
			for(int j = 1; j <= d[c[name[i]]]; j++) {
				if (b[a[c[name[i]]][j]] == 0) continue;
				string s = a[c[name[i]]][j];
				int t = s.size();
				for(int k = 1; k < t; k++) {
					s.erase(0, 1);
					if (b[s] != 0) b[s] = 0;
				}
			}
			int K = d[c[name[i]]];
			d[c[name[i]]] = 0;
			for(int j = 1; j <= K; j++) {
				if (b[a[c[name[i]]][j]] != 0)
					a[c[name[i]]][++d[c[name[i]]]] = a[c[name[i]]][j], b[a[c[name[i]]][j]] = 0;
			}
		}
	}
	int M = 0;
	for(int i = 1; i <= n; i++) if (c[name[i]] == i) ++M;
	cout << M << endl;
	for(int i = 1; i <= n; i++) {
		if (c[name[i]] == i) {
			cout << name[i] << " " << d[i] << " ";
			for(int j = 1; j <= d[i]; j++) cout << a[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
