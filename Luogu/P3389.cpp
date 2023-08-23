//*** Le vent se lève, il faut tenter de vivre! ***
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 105;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n;
double Matrix[maxn][maxn];
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n+1;j++){
            Matrix[i][j]=read();
        }
    }
    for(int i = 1;i<=n;i++){
        int mx = i;
        for(int j = i+1;j<=n;j++){
            if(fabs(Matrix[j][i])>fabs(Matrix[mx][i])) mx=j;
        }
        if(fabs(Matrix[mx][i])<=0.00000000000000000)return printf("No Solution")&0;
        if(mx!=i)swap(Matrix[mx],Matrix[i]);
        double div=Matrix[i][i];
        for(int j = i;j<=n+1;j++)Matrix[i][j]/=div;
        for(int j = 1;j<=n;j++){
            div = Matrix[j][i];
            if(j==i)continue;
            for(int k = i;k<=n+1;k++){
                Matrix[j][k]-=div*Matrix[i][k];
            }
        }        
    }
    for(int i = 1;i<=n;i++){
        printf("%.2lf\n",Matrix[i][n+1]);
    }
}