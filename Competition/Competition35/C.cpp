#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string str;
const int maxn=1000;
int a[maxn+50][maxn+50];
int row[maxn+50],col[maxn+50];
ll sum[maxn+50][maxn+50];

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (;T--;){
		int n,m;
		cin >> n >> m;
		for (int i=1;i<=n;i++){
			cin >> str;
			for (int j=1;j<=m;j++){
				if (str[j-1]=='G'){
					a[i][j]=0;
					row[i]=j;
					col[j]=i;
				}
				else a[i][j]=1;
			}
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j]; 
		ll ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) if (a[i][j]){
				ans+=(sum[i-1][m]-(sum[n][m]-sum[i][m]))*i;
				ans+=(sum[n][j-1]-(sum[n][m]-sum[n][j]))*j;
			}
		}
		for (int i=1;i<=n;i++) if (row[i]){
			int last=row[i],d=0;
			for (int j=i;j<=n;j++){
				if (row[j]==0) break;
				if (d*(row[j]-last)<0) break;
				d=row[j]-last;
				last=row[j];
				if (row[i]<row[j]) ans+=(row[i]-1)*(m-row[j])*2;
				else ans+=(row[j]-1)*(m-row[i])*2;
			}
		}
		for (int i=1;i<=m;i++) if (col[i]){
			int last=col[i],d=0;
			for (int j=i;j<=m;j++){
				if (col[j]==0) break;
				if (d*(col[j]-last)<0) break;
				d=col[j]-last;
				last=col[j];
				if (col[i]<col[j]) ans+=(col[i]-1)*(n-col[j])*2;
				else ans+=(col[j]-1)*(n-col[i])*2;
			}
		}
		printf("%.4lf\n",2.0*ans/sum[n][m]/sum[n][m]);
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
	}
	return 0;
}
