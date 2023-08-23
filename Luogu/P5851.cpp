#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
int w,l,r,g[301][301],p[305][305][305];
int main(){
    n=read(),m=read();
    for(int i = 1;i<=m;i++){
        w=read(),l=read(),r=read();
        for(int j = l;j<=r;j++){
            p[j][l][r]=w;
        }
    }
    for(int k = 1;k<=n;k++){
        for(int i = k;i>=1;i--){
            for(int j=k;j<=n;j++){
                if(i!=1)p[k][i-1][j]=max(p[k][i][j],p[k][i-1][j]);
                if(j!=n)p[k][i][j+1]=max(p[k][i][j],p[k][i][j+1]);
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j = i;j<=n;j++){
			for(int k=i;k<=j;k++){
				g[i][j]=max(g[i][j],(k!=i)*g[i][k-1]+(k!=j)*g[k+1][j]+p[k][i][j]);
			}
        }
    }
    cout<<g[1][n];
}