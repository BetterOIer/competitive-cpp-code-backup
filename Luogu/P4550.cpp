/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
int n;
double f[10005],g[10005];
int main() {
	scanf("%d",&n);
	for(int i=n-1;~i;--i) {
		f[i]=f[i+1]+(1.0*n)/(1.0*(n-i));
		g[i]=(1.0*i)/(1.0*(n-i))*(f[i]+1)+g[i+1]+f[i+1]+1;
	}
	printf("%.2lf\n",g[0]);
	return 0;
}
