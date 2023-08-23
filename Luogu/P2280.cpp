#include<iostream>
using namespace std;
int n,m,dt[5010][5010],N=5001,ans=0;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
		int x, y, v;
		cin>>x>>y>>v;
        dt[y+1][x+1]=v;
    }
    for (int i=1;i<= N;i++){
		for (int j=1; j<=N;j++){
			dt[i][j] = dt[i - 1][j] + dt[i][j - 1] - dt[i - 1][j - 1] + dt[i][j];
        }
    }
    for(int i = m;i<=N;i++){
        for (int j = m; j <= N; j++){
            int data = dt[i][j]-dt[i-m][j]-dt[i][j-m]+dt[i-m][j-m];
            ans = max(ans, data);
        }
    }
    cout<<ans;
}