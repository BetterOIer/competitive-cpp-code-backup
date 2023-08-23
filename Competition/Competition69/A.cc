#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,f[3005][4],a[3005],b[3005];
int main(){
	memset(f,-0x3f,sizeof(f));f[0][0]=0;
	n=read(),m=read();
	for(register int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for(register int i=1;i<=n;i++)
		for(register int j=m;j>=0;j--) {
            f[j][2]=max(f[j][2],f[j][1]);
            if(j>=a[i]) f[j][1]=max(f[j-a[i]][1]+b[i],f[j-a[i]][0]+b[i]);
            if(j>=a[i]) f[j][3]=max(f[j][3],max(f[j-a[i]][2]+b[i],f[j-a[i]][3]+b[i]));
		}
	for(register int i=1;i<=m;i++)
		printf("%d ",(f[i][3]>0?f[i][3]:-1));
}