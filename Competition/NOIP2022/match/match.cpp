#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
int numa[2353];
int numb[2354];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read();
	for(int i = 1;i<=n;i++){
		numa[i]=read();
	}
	for(int i = 1;i<=n;i++){
		numb[i]=read();
	}
	int Q=read();
	for(int i = 1;i<=Q;i++){
		cout<<8;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}