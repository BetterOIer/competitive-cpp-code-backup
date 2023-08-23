/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
#define MAXN 510
#define MAXM 250010
#define eps 1e-8
#define MOD 1000000007
#define INF 1000000000
int n;
int C[MAXN][MAXN];
int L[MAXN][MAXN];
int R[MAXN][MAXN];
int l[MAXM],r[MAXM],c[MAXM],tot;
int p[MAXM];
long long sum;
long long suma;
bool cmp(int x,int y){
	return c[x]<c[y];
}
int main(){
	int I,i,j,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&C[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&L[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&R[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		tot++;
		l[tot]=L[i][i];
		r[tot]=R[i][i];
		c[tot]=C[i][i]*2;
	}
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			tot++;
			l[tot]=max(L[i][j],L[j][i])*2;
			r[tot]=min(R[i][j],R[j][i])*2;
			c[tot]=C[i][j]+C[j][i];
		}
	}
	for(i=1;i<=tot;i++){
		p[i]=i;
		sum+=(long long)c[i]*r[i];
		suma+=r[i];
	}
	sort(p+1,p+tot+1,cmp);
	for(I=1;I<=tot;I++){
		i=p[I];
		if(r[i]-l[i]<suma){
			sum-=(long long)(r[i]-l[i])*c[i];
			suma-=r[i]-l[i];
		}else{
			sum-=(long long)c[i]*suma;
			if(i>n&&(suma&1)){
				int x=I-1,y=I+1;
				while(p[x]>n&&x){
					x--;
				}
				while(p[y]>n&&y<=tot){
					y++;
				}
				x=p[x];
				y=p[y];
				if(x!=0&&(y>tot||c[i]-c[x]<=c[y]-c[i])){
					sum+=c[x]-c[i];
				}else{
					sum+=c[i]-c[y];
				}
			}
			break;
		}
	}
	printf("%lld\n",sum/2);
	return 0;
}
