/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n;
double a[20][20],c[20][20];
int main(){
    n=read();
    for(int i = 1;i<=n+1;i++){
        for(int j = 1;j<=n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            c[i][j]=(a[i][j]-a[i+1][j])*2;
            c[i][n+1]+=(a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            if(fabs(c[j][i]>1e-8)){
                swap(c[i],c[j]);
            }
        }
        for(int j = 1;j<=n;j++){
            if(i==j) continue;
            double div = c[j][i]/c[i][i];
            for(int k = i;k<=n+1;k++)c[j][k]-=c[i][k]*div;
        }
    }
    for(int i = 1;i<=n;i++)printf("%.3lf ",c[i][n+1]/c[i][i]);
}